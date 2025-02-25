# MAZE

Реализация проекта «Лабиринт»

## Часть 1. Реализация проекта «Лабиринт»

Необходимо реализовать программу-лабиринт, которая может генерировать и отображать идеальные лабиринты и пещеры:

- [+] Программа должна быть разработана на языке Си.
- [+] При написании программы необходимо использовать стандартный стиль написания кода для выбранного языка.
- [+] Код программы должен находиться в папке src
- [+] Программа должна быть собрана с помощью Makefile, который содержит стандартный набор целей для GNU-программ: all, install, uninstall, clean, tests. Каталог установки может быть любым, за исключением каталога сборки
- [] Программа должна реализовывать консольный пользовательский интерфейс.
 Используем  ИГА:
  состояния:
    1 - MENU
    2 - GENERATE_MAZE (input size maze);
    3 - LOAD_MAZE_FROM_FILE (input file path);
    4 - FIND_PATHAWAY;
    5 - EXIT_STATE;

    принимаемые сигналы:
    1 - up
    2 - down
    3 - enter
    4 - esc



- [] В программе есть возможность загрузки лабиринта из файла, который задан в формате, описанном выше.
- [] Максимальный размер лабиринта 50x50.
- [] Загруженный лабиринт должен быть отображен на экране в консоли в псевдографике.
Толщина «стенки» — 1 символ
Размер самих ячеек лабиринта рассчитывается таким образом, чтобы лабиринт занимал все отведенное ему поле.


### Часть 2. Создание идеального лабиринта

Добавьте возможность автоматически генерировать идеальный лабиринт.
Лабиринт считается идеальным, если из каждой точки в любую другую точку можно попасть только одним способом.

- [] Вам необходимо сгенерировать лабиринт по алгоритму Эллера.
- [] Сгенерированный лабиринт не должен иметь изолирований и петель.
- [] Подготовить полное покрытие модуля идеальной генерации лабиринта с помощью модульных тестов
- [] Пользователь вводит только размерность лабиринта: количество строк и столбцов.
- [] Сгенерированный лабиринт необходимо сохранить в формате файла, описанном выше.
- [] Созданный лабиринт должен отображаться на экране, как указано в первой части.

### Часть 3. Решение лабиринта

Добавьте возможность показывать решение любого лабиринта, отображаемого в данный момент на экране:

- [] Пользователь устанавливает начальную и конечную точки
- [] Маршрут, являющийся решением, должен быть отображен «линией» толщиной в 1 символ, проходящей через середину всех ячеек лабиринта, через который проходит решение.
- [] Цвет линии раствора должен отличаться от цвета стен и поля.
- [] Подготовить полное покрытие модуля решения лабиринтов с помощью модульных тестов


### Часть 4. Бонус. Генерация пещеры

Добавьте генерацию пещер с использованием клеточного автомата :

- [] Пользователь указывает файл, описывающий пещеру, в соответствии с форматом, описанным выше.
- [] Максимальный размер пещеры 50x50.
- [] Загруженная пещера должна быть отображена на экране в консоли в псевдографике.
- [] Пользователь устанавливает пределы «рождения» и «смерти» ячейки, а также вероятность стартовой инициализации ячейки.
- [] Лимиты «рождения» и «смерти» могут иметь значения от 0 до 7.
- [] Клетки вне пещеры считаются живыми.
- [] Должен быть реализован пошаговый режим отображения результатов алгоритма в двух вариантах:
    - Следующий шаг приведет к рендерингу следующей итерации алгоритма.
    - Автоматический вариант работы запускает рендеринг итераций алгоритма с частотой 1 шаг в Nмиллисекундах, где количество миллисекунд Nзадается пользователем отдельно.
- [] Размер ячеек в пикселях рассчитывается таким образом, чтобы пещера занимала все отведенное ей поле.
- [] Подготовить полное покрытие модуля генерации пещер с помощью модульных тестов



### Часть 5. Бонус. ML. Обучение с подкреплением

С помощью обучения с подкреплением необходимо разработать алгоритм обучения агента кратчайшему прохождению лабиринтов:

- [] Пользователь указывает файл, описывающий лабиринт и конечную точку.
- [] Агент должен уметь находить выход из лабиринта из любой начальной точки.
- [] Необходимо использовать метод Q-learning
- [] Агент обучается на одном лабиринте, который не меняется ни в процессе обучения, ни на этапе тестирования; конечная точка также фиксирована.
- [] Модуль обучения агента должен быть полностью покрыт модульными тестами.

Необходимо предоставить пользователю возможность взаимодействия с обученным агентом:

- [] Пользователь определяет начальную точку
- [] Маршрут, построенный агентом из заданной точки, отображается в соответствии с правилами, описанными выше.

Модули обучения и взаимодействия агентов следует разрабатывать на языке C без использования готовых библиотек обучения с подкреплением.



### Часть 6. Бонус. Веб-интерфейс
Добавить веб-версию пользовательского интерфейса в любом формате (MPA, SPA) с использованием соответствующих фреймворков. Веб-интерфейс должен соответствовать как минимум всем основным функциональным требованиям из частей выше ( Часть 1 - Часть 3 ).