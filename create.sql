CREATE TABLE `users`
(
    `id` INT AUTO_INCREMENT,
    `login` VARCHAR(127),
    `password` varchar(255),

    PRIMARY KEY (`id`)
);
INSERT INTO `users` (`login`, `password`) VALUES
('admin', MD5('password#salt'));

CREATE TABLE `objects`
(
    `id` INT AUTO_INCREMENT,
    `parent` INT DEFAULT 0,
    `title` VARCHAR(127),
    `description` TEXT,
    `deleted_at` DATETIME,

    PRIMARY KEY (`id`)
);
INSERT INTO `objects` (`parent`, `title`, `description`) VALUES
(0, 'Бенчмаркинг', '(bench — «скамья» и mark — «отмечать») — процесс сравнения своей деятельности с лучшими компаниями на рынке и в отрасли с последующей реализацией изменений для достижения и сохранения конкурентоспособности.'),
(0, 'Бизнес-ангел', '– частный инвестор, который приобретает долю в перспективном проекте, обеспечивая финансовую и экспертную поддержку на старте с целью получения прибыли в будущем.'),
(0, 'Бирюзовые организации', '— «компании будущего», которые развиваются подобно живому организму. В бирюзовых организациях есть общая эволюционная цель, нет жесткой иерархии и строгих приказов сверху, а сотрудники воспринимаются как личности, а не ресурсы.'),
(0, 'Блеймсторминг', '(blame — «вина» и storm — «штурм») — метод коллективного поиска человека или причины, которые помешали выполнению поставленной задачи.'),
(0, 'Бутстрэппинг', '(bootstrapping — затягивание ремешков обуви) — способ начала и развития своего бизнеса при очень незначительном финансировании извне или при полном его отсутствии.'),
(1, 'Геймификация', '– использование игровых подходов для неигровых процессов. Например, для усиления лояльности клиентов или повышения вовлеченности пользователей.'),
(2, 'Дауншифтинг', '(downshifting — переключение автомобиля на более низкую передачу) — жизненная философия, предполагающая отказ от успешной карьеры и большой зарплаты ради жизни «для себя».'),
(3, 'Демаркетинг', '— вид маркетинга, направленный на снижение спроса среди всей целевой аудитории или определенных ее групп.'),
(4, 'Демпинг', '(dumping — сброс) — продажа товаров и услуг по искусственно заниженным ценам.'),
(6, 'Диверсификация', '— расширение ассортимента выпускаемой продукции и переориентация рынков сбыта, освоение новых видов производств.'),
(7, 'Долина смерти', '— самый сложный период жизни стартапа, при котором проект уже запущен, но прибыли еще нет и неизвестно, будет ли.'),
(8, 'Компания-единорог', '– это стартап, оценочная стоимость которого быстро взлетает до миллиарда долларов и выше.'),
(10, 'Лид', '(to lead — приводить) — потенциальный клиент, который проявил заинтересованность к товарам или услугам компании, и оставил свои контактные данные для дальнейшей коммуникации.'),
(11, 'Митап', '(meet up – встречаться) – встреча специалистов и единомышленников для обсуждения тех или иных вопросов, обмена опытом в неформальной обстановке.'),
(5, 'Омниканальность', '– маркетинговый термин, обозначающий взаимную интеграцию разрозненных каналов коммуникации в единую систему, с целью обеспечения бесшовной и непрерывной коммуникации с клиентом.'),
(6, 'Пивот', '(pivot — вращаться) — смена бизнес-модели, продукта или сферы деятельности стартапа.'),
(7, 'Питч', '(pitch – бросок, подача) — краткая структурированная презентация проекта перед потенциальными инвесторами.'),
(8, 'Факап', '(fuck up — проиграть, провалиться) — сленговое выражение, которое в буквальном смысле означает колоссальный провал, неудачу или проигрыш.'),
(9, 'Холакратия', '— принцип организации бизнес-процессов в компании, предполагающий децентрализацию власти, при которой любой сотрудник может влиять на принятие решений.'),
(15, 'Шеринг-экономика', '(sharing economy или сollaborative сonsumption—экономика совместного потребления) — понятие, которое используется для обозначения экономической модели, основанной на коллективном использовании товаров и услуг, бартере и аренде вместо владения.'),
(16, 'Burn rate', '— скорость, с которой компания тратит денежные резервы для финансирования текущей деятельности до получения положительного денежного потока.'),
(17, 'LTV', '(Lifetime Value) — совокупная прибыль компании, получаемая с одного клиента за все время сотрудничества с ним. Иначе LTV называют пожизненной стоимостью клиента.'),
(18, 'NPS', '(Net Promoter Score) — общепринятый индекс удовлетворенности клиента, измеряющий готовность рекомендовать товары или услуги компании другим людям по десятибалльной шкале.'),
(19, 'ROI', '(Return On Investment) — коэффициент возврата инвестиций, иллюстрирующий уровень доходности или убыточности бизнеса, учитывая сумму сделанных в этот бизнес инвестиций.'),
(20, 'UGC', '(User Generated Content) — оригинальный контент, который создают пользователи. Например, отзывы, фото или видео с продуктом, комментарии.');