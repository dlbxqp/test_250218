<?php
session_start();

require './router.inc';
?><!DOCTYPE html>
<html lang='ru'>
    <head>
        <meta charset='utf-8'>

        <title>Проверочное задание 250218</title>

        <link rel="stylesheet" href="../assets/styles/normalize.css">
        <link rel="stylesheet" href="../assets/styles/main.css">
        <link rel="stylesheet" href="s.css">
    </head>
    <body>
<?php if(isset($content_header)):?>
        <header class="header"><?= $content_header?></header>
<?php endif?>
<?php if(isset($content_main)):?>
        <main class="root"><?= $content_main?></main>
<?php endif?>
    </body>
</html>
