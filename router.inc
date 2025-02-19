<?php
require './includes/db_connect.inc';
require './Objects.php';

$Objects = new Objects($dbh);


if( isset($_GET['object_id']) ){

    exit( json_encode( $Objects->getDescription($_GET['object_id']) ) );

} elseif( isset($_GET['parent_id']) ) {

    exit( json_encode( $Objects->getChildrens($_GET['parent_id']) ) );

}