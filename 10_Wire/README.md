#Провода (6)
Дано N отрезков провода длиной L 1 , L 2 , ..., L N сантиметров. Требуется с помощью разрезания
получить из них K равных отрезков как можно большей длины, выражающейся целым числом
сантиметров. Если нельзя получить K отрезков длиной даже 1 см, вывести 0.
Ограничения: 1 ≤ N ≤ 10 000, 1 ≤ K ≤ 10 000, 100 ≤ L i  ≤ 10 000 000, все числа целые, время 1 с.
Ввод из файла INPUT.TXT. В первой строке находятся через пробел числа N и К. В следующих
N строках - L 1 , L 2 , ..., L N , по одному числу в строке.
Вывод в файл INPUT.TXT. Вывести одно число - полученную длину отрезков.
Пример
Ввод
4 11
802
743
457
539
Вывод
200
Подсказка. Использовать бинарный поиск.