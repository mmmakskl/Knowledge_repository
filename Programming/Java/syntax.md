- final == const
- Константа класса == static final
> При некоторых неверных математичиских вычислениях java не выкинет исключения, для этого надо использовать Math.\*Exact() (multiply, add, subtract, increment, decrement, negate)

**Поразрядные операции:** & - (И);| - (ИЛИ);^ - (исключающее ИЛИ);~ - (НЕ); 

(>>;<<) - сдвигают двоичное представление числа вправо или влево, >>> - заполняет старшие разряды нулями, <<< - нет

#### Потоки ввода:
Для чтения нужно создать объект типа Scanner `Scanner in = new Scanner(System.in);`
Для скрытого ввода создать объект типа `Console` `Console cons = System.console();`

#### Потоки вывода: 
Вывести число с заданной точностью (8 целых, 2 дробных) `System.out.printf("%8.2f", x);`
**printf()** - спецификаторы:
// Добавить скрин 89 страница таблица 3.6
```
System.out.printf("%1$s %2$ty %2$tb %2$td %2$tr", "Now:", new Date());

>> Now: 24 сент. 17 09:13:59 PM
```
![[printf_spec.png]]

#### Файловый ввод и вывод
***Чтение:***
`Scanner in = new Scanner(Path.of("myfile.txt"), StandardCharsets.UTF_8);`
При чтении вводимой строки используются методы `next*` -> (`Double`, `Int`, `Line` и тд.)прочитать одно слово, `next`
***Запись:***
`PrintWriter out = new PrintWriter("myfile.txt", StandardCharsets.UTF_8);`
Также для вывода можно пользоваться `print(), printf(), println()`

#### Циклы
- `if-else` - база
- `while` - база
- `do-while` - сначала выполняется условие а в конце идет проверка
```
do
{
    n++;
}
while (int n <= 10)
```
- `for` - база
- `switch-case`
```
switch (choice)
{
    case 1:
        . . .
        break;
    case 2:
        . . .
        break;
    . . .
    default:
        . . .
        break;
}
```
- **Метки** - можно поставить метку перед любым оператором (`if-else`, `for`, блоком {} и тд. тп.), чтобы при определенном условии его остановить оператором `break`
##### Шаблон:
```
метка: //цикл, блок
{
. . .
    if (условие)
        break метка; //выход из блока
        . . .
}
```
##### Пример:
```
Scanner in = new Scanner(Systern.in);
int n;
read data:
while (. . .) //Этот цикл помечен меткой
{
    for ( . . . ) //Этот цикл не помечен
    {
        System. out. print ( "Enter а numЬer >= О: ");
        n = in.nextlnt();
        if (n < 0) //условие для прерывания цикла
            break read_data;
            // прервать цикл
    }
    // этот оператор выполняется сразу же после
    // оператора break с меткой
    if (п < 0) //поверить наличие недопустимой ситуации
    {
        // принять меры против недопустимой ситуации
    }
    else
    {
    // выполнить действия при нормальном ходе
    // выполнения программы
    }
}
```
- `continue` - оператор выполняет переход в начало цикла, пропуская оставшуюся часть текущего шага цикла. Так же есть оператор `continue` с меткой, передающий управление заголоовку оператора цикла, помеченного соответствующей меткой.
```
Scanner in
new Scanner(System.in);
while (sum < goal)
{
    System.out.print("Enter а numЬer: ");
    n = in.nextint();
    if (n < 0) continue;
    sum += n; //не выполняется, если n < О
}
```

#### Большие числа
Классы `BigInteger` и `BigDecimal` из пакета java.math
С ними не работают базовые операции +, \*, вместо этого используются методы `add()` и `multiply()`
И можество других методов находятся на стр.112 Хорстманн - Java

#### Массивы
Объявление: `int[] a` or `int a[]`


### Здравая тема
условие ? выражение\_1 : выражение\_2


Почитать про кодовые точки в строках и символьную строку а именно StringBuilder
-> Кодовые точки
-> StringBuilder


#### new vs valueOf

Старайтесь всегда использовать метод valueOf вместо конструктора в стандартных классах-оболочках примитивных типов, кроме тех случаев, когда вам нужно конкретно выделить память под новое значение.

Все оболочки, кроме чисел с плавающей точкой, от Byte до Long, имеют кэш. По умолчанию этот кэш содержит значения от -128 до 127. Следовательно, если ваше значение попадает в этот диапазон, то значение вернется из кэша. Значение из кэша достается в 3.5 раза быстрее, чем при использовании конструктора, плюс идёт экономия памяти.

Помимо этого, наиболее часто используемые значения могут также быть закэшированы компилятором и виртуальной машиной.

![[IMG_20240921_110628_776.jpg]]![[IMG_20240921_110629_303 1.jpg]]
