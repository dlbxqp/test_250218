<?php
$content_header = <<<HD
<p>Вы авторизованы как <strong>{$login}</strong></p>
<a href="/admin?exit">Выйти</a>

HD;


$objects = '';
$selectItems = <<<HD
<option value="0" selected>root</option>


HD;

$allObjects = $Objects->getAll();

function createHierarchy (&$input, &$output, $parent = 0) {
    if(!is_array($input) or !is_array($output)) return false;

    foreach ($input as $v) {
        if ($v['parent'] == $parent) {
            $v['children'] = [];
            createHierarchy($input, $v['children'], $v['id']);
            $output[] = $v;
        }
    }

    return true;
}
$allObjects_ = [];
createHierarchy($allObjects, $allObjects_);

function htmlTree($tree) {
    $treeHtml = '<ol class="list">';
    foreach ($tree as $v) {
        $treeHtml .= <<<HD
<li class="list__item">
    <h2 class="item__title">{$v['title']}</h2>
    <p class="item__description">{$v['description']}</p>
    <div class="item__actions">
        <button class="actions__element actions__edit" data-id="{$v['id']}">edit</button>
        <button class="actions__element actions__delete" data-id="{$v['id']}">delete</button>
    </div>
    
HD;
        if(!empty($v['children'])) $treeHtml .= htmlTree($v['children']);
        $treeHtml .= '</li>';
    }
    $treeHtml .= '</ol>';

    return $treeHtml;
}
$ol = htmlTree( $allObjects_ );

$content_main = <<<HD
<link rel="stylesheet" href="/admin/views/objects/s.css">
        
<div class="objects">{$ol}</div>

<div class="popup" id="object-popup">
    <form action="/admin" method="POST" class="popup-form" id="popup-form">
        <button class="popup-form__close" id="popup-close">+</button>
        <input type="hidden" name="id" id="object-id" />
        <label class="popup-form__row">
            <input class="popup-form__element popup-form__input" id="object-title" name="title" placeholder="Заголовок" />
        </label>
        <label class="popup-form__row popup-form__row_full-grown">
            <textarea class="popup-form__element popup-form__textarea" id="object-description" name="description" placeholder="Содержание"></textarea>
        </label>
        <label class="popup-form__row">
            <select class="popup-form__element popup-form__select" id="object-parent" name="parent">{$selectItems}</select>
        </label>
        <label class="popup-form__row popup-form__row_save">
            <button class="popup-form__element popup-form__save" id="popup-save">Сохранить</button>
        </label>
    </form>
</div>

<script src="/admin/views/objects/s.js"></script>

HD;
