<?php
define('MYSQL_HOST', 'mysql-5.6');
define('MYSQL_DATABASE', 'test_250218');
define('MYSQL_USER', 'root');
define('MYSQL_PASSWORD', '');

try {
    $dbh = new PDO(
        "mysql:host=" . MYSQL_HOST . ";dbname=" . MYSQL_DATABASE,
        MYSQL_USER,
        MYSQL_PASSWORD,
        [PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES 'utf8'"]
    );
} catch (PDOException $e) {
    die($e->getMessage());
}