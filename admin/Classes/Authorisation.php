<?php
class Authorisation
{
    public $message = null;
    protected $dbh = null;

    public function __construct (PDO $dbh) {
        $this->dbh = $dbh;
    }

    public function signIn($login, $password)
    {
        try {
            $sth = $this->dbh->prepare("SELECT `id` FROM `users` WHERE `login` = :login AND `password` = :password LIMIT 1");
            $sth->execute([
                'login' => $login,
                'password' => md5("{$password}#salt")
            ]);
            if( $sth->fetch(PDO::FETCH_ASSOC) ){
                $_SESSION['latch'] = date('ymd') . '|' . $login;
            } else{
                $this->setMessage('Пользователей с таким логином и паролем не найдено в системе');
            }
            header('Location: /admin');
        } catch (PDOException $e) {
            $this->setMessage($e->getMessage());
        };
    }

    public function signOut()
    {
        unset($_SESSION['latch']);

        header('Location: /');
    }

    public function signCheck () {
        $a_latch = explode('|', $_SESSION['latch']);

        if ($a_latch[0] !== date('ymd')) {
            unset($_SESSION['latch']);

            $this->setMessage('Время сессии истекло - повторите вход в систему');
        }

        return $a_latch[1];
    }

    private function setMessage($message)
    {
        setcookie('authorisation_message', $message, time() + 10, '/admin');
    }
}