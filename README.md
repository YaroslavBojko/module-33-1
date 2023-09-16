# module-33-1
Задание 1. Работа корзины с покупками

Что нужно сделать

Реализуйте простую и безопасную модель работы корзины онлайн-магазина.

В начале программы вы заполняете базу данных самого магазина через стандартную консоль. Каждый элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
Корзина должна поддерживать следующие операции: добавление товара с указанным его количеством — add, удаление товара с указанным количеством — remove. Обе операции принимают артикул товара в виде строки и количество в виде целого числа.
При вводе аргументов к операциям должна осуществляться их валидация. Артикул должен быть в базе данных магазина, количество не должно превышать количество доступного продукта на складе (при удалении — в корзине).
Рекомендации

В качестве контейнера для базы данных и самой корзины можете использовать std::map.

Если пользователь ввёл некорректную информацию, то лучше выбросить std::invalid_argument, в других случаях — runtime_error. 
