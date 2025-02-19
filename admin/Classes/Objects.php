<?php
class Objects
{
    protected $dbh = null;

    public function __construct (PDO $dbh) {
        $this->dbh = $dbh;
    }

    public function getAll($except = null){
        $and  = isset($except) ? "AND `id` <> {$except} AND `parent` <> {$except}" : '';

        $sth = $this->dbh->query("
SELECT
    `id`,
    `parent`,
    `title`,
    `description`
FROM `objects`
WHERE `deleted_at` IS NULL
{$and}
ORDER BY `id`
");

        return $sth->fetchAll(PDO::FETCH_ASSOC);
    }

    public function getOne($id)
    {
        $sth = $this->dbh->prepare("
SELECT
    `id`,
    `parent`,
    `title`,
    `description`
FROM `objects`
WHERE `id` = ?
LIMIT 1
");
        $sth->execute([
            $id
        ]);

        return $sth->fetch(PDO::FETCH_ASSOC);
    }

    public function updateObject($id, $title, $description, $parent)
    {
        $sth = $this->dbh->prepare("
UPDATE `objects`
SET `title` = :title,
    `description` = :description,
    `parent` = :parent
WHERE `id` = :id
");
        $sth->execute([
            'id' => $id,
            'title' => $title,
            'description' => $description,
            'parent' => $parent
        ]);

        $this->setMessage('updated_object', $id);
    }

    public function deleteObject($id)
    {
        $sth = $this->dbh->prepare("
UPDATE `objects`
SET `deleted_at` = NOW()
WHERE `id` = ?
");
        $sth->execute([
            $id,
        ]);
    }

    private function setMessage($title, $message)
    {
        setcookie($title, $message, time() + 10, '/admin');
    }
}