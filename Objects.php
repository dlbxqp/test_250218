<?php
class Objects
{
    protected $dbh = null;

    public function __construct (PDO $dbh) {
        $this->dbh = $dbh;
    }

    public function getChildrens($parentId = 0){
        $sth = $this->dbh->prepare("
SELECT
    `id`,
    `title`
FROM `objects`
WHERE `deleted_at` IS NULL
AND `parent` = ?
ORDER BY `id`
");
        $sth->execute([
            $parentId
        ]);

        return $sth->fetchAll(PDO::FETCH_ASSOC);
    }

    public function getDescription($id)
    {
        $sth = $this->dbh->prepare("
SELECT
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
}