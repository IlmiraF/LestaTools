# LestaTools

Готовое запускаемое решение : https://github.com/IlmiraF/LestaTools/releases

При открытии программы, доступен минимальный набор типов объектов.

![Снимок экрана 2024-05-01 150136](https://github.com/IlmiraF/LestaTools/assets/70852983/679fc851-9fad-400a-a778-d3180bdb8ded)

Можно добавлять объекты с уникальным именем и удалять их, с помощью нажатий на клавиши “Enter” и “Delete” соответственно, или, с помощью кнопок “Add Object” и “Command” -> “Delete Object”.

Можно открывать уже существующие списки объектов и сохранять их. Для этого нужно выбрать подходящий файл, с помощью кнопки “Open File”. А чтобы сохранить список в файл, нужно нажать кнопку “Save File”. Если ранее никакой файл не был открыт, программа предложит выбрать файл для записи и после этого еще раз нажать “Save File”. Программа работает с документами с расширением .json.

![Снимок экрана 2024-05-01 150312](https://github.com/IlmiraF/LestaTools/assets/70852983/dff46a3f-2617-4603-acf1-f808e2c9039e)

Программа оснащена командами отменить/вернуть. С помощью них можно предотвратить/допустить добавление или удаление объекта.

![Снимок экрана 2024-05-01 150357](https://github.com/IlmiraF/LestaTools/assets/70852983/c9705dd7-7359-4cd8-b3cb-90710e754f47)

При двойном нажатии на элемент списка, откроется окно просмотра и редактирования свойств объекта.
В этом окне отображаются иконка объекта и 4 возможных свойства.

![Снимок экрана 2024-05-01 150426](https://github.com/IlmiraF/LestaTools/assets/70852983/38410bf1-7dab-4246-acdb-bb36870d69b2)

При двойном нажатии на свойство Image, можно изменить иконку объекта. Откроется окно выбора изображения, после в колонке отобразится путь до файла и само изображение.

Свойство Material может принимать одно из значений (Steel, Stone, Wood) или не иметь данного свойства, т.е. “None”.

![Снимок экрана 2024-05-01 150505](https://github.com/IlmiraF/LestaTools/assets/70852983/a9031fbd-7ce0-438f-852c-3891746ef258)

Свойство Speed характеризуется положительным значением с плавающей точкой.

![Снимок экрана 2024-05-01 150613](https://github.com/IlmiraF/LestaTools/assets/70852983/0bfce578-ffd3-4fdc-9333-59f0ef7ddff2)

Свойство Points описывается целым положительным числом.

![Снимок экрана 2024-05-01 150641](https://github.com/IlmiraF/LestaTools/assets/70852983/c588ce4a-4b52-4133-9177-b09b4e647874)

При закрытии программа предупреждает о несохраненных изменениях, если : 
  - были добавлены или удалены объекты
  - было отредактировано свойство(-ва) объекта.

![Снимок экрана 2024-05-01 150723](https://github.com/IlmiraF/LestaTools/assets/70852983/4d2d9aa8-d017-4dc8-be85-a89862871816)
