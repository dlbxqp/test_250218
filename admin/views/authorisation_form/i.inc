<?php
if (isset($_COOKIE['authorisation_message'])) {
    $authorisationMessage = <<<HD
<p class="authorisation__message">{$_COOKIE['authorisation_message']}</p>

HD;
}

$content_main = <<<HD
<link rel="stylesheet" href="/admin/views/authorisation_form/s.css">

{$authorisationMessage}

<form action="/admin/index.php" method="POST" class="authorisation-form">
    <label>
        <input class="authorisation-form__element authorisation-form__input" name="l">
    </label>
    <label>
        <input class="authorisation-form__element authorisation-form__input" name="p" type="password">
    </label>
    <label>
        <button class="authorisation-form__element authorisation-form__button" disabled>sign in</button>
    </label>
</form>

<script src="/admin/views/authorisation_form/s.js"></script>

HD;
