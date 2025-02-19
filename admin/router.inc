<?php
require './Classes/Authorisation.php';
require './Classes/Objects.php';
require '../includes/db_connect.inc';


$Authorisation = new Authorisation($dbh);
$Objects = new Objects($dbh);


if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    if (!empty($_POST['l']) && !empty($_POST['p'])) {

        $Authorisation->signIn($_POST['l'], $_POST['p']);

    } else {

        $_POST = json_decode(file_get_contents('php://input'), true);
        if (
            !empty($_POST['id'])
            && !empty($_POST['title'])
            && !empty($_POST['description'])
        ) {
           $Objects->updateObject(+$_POST['id'], $_POST['title'], $_POST['description'], $_POST['parent']);
        }

    }

} elseif ( isset($_GET['select_id']) ) {

    exit( json_encode($Objects->getAll(+$_GET['select_id']), JSON_UNESCAPED_UNICODE) );

} elseif ( isset($_GET['object_id']) ) {

    exit( json_encode($Objects->getOne(+$_GET['object_id']), JSON_UNESCAPED_UNICODE) );

} elseif ( isset($_GET['deleted_id']) ) {

    $Objects->deleteObject($_GET['deleted_id']);

} elseif ( isset($_GET['exit']) ) {

    $Authorisation->signOut();

} elseif ( isset($_SESSION['latch']) ) {

    $login = $Authorisation->signCheck();

    require './views/objects/i.inc';

} else {

    require './views/authorisation_form/i.inc';

}