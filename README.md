# README


## Task 1 and Task 2 

1. Необходимо реализовать схему взаимодействия процессов «читатели-писатели» под ОС Windows с использованием соответствующих системных вызовов WinAPI и многопоточности, используя thread, event, и mutex. Приоритет может быть любым. Потоки должны разделять общее адресное пространство. Количество читателей, писателей, повторов программы, а также временные задержки, задаются директивами препроцессора. Обеспечить вывод на экран результат работы читателей и писателей.



2. Необходимо разработать приложение, отображающее список подразделений предприятия и его сотрудников в виде дерева. Список должен загружаться из файла формата xml. Программа должна обеспечить возможность добавления, удаления, редактирования подразделений и сотрудников в них. Программа должна обеспечить возможность отмены и возврата изменений. При разработке необходимо использовать паттерны проектирования (xml файл с данными прикреплен к заданию).
Поля сотрудника:
- ФИО;
- должность;
- зарплата (целое число).
Поля подразделения:
- наименование;,
- количество сотрудников;
- средняя зарплата.

### My_Comments

In the Task2 I wrote several insert functions to the XML File. Using two third party TinyXML TinyXMLPath libraries. In the project has 4 .cpp library files: tinyxmlerror.cpp , tinyxml2.cpp, tinyxmlparser.cpp, tinydelxml.cpp  and 2 headers: tinystr.h , tinyxml2.h.  Everything else is built according to the basic algorithms for implementing UNDO, REDO via Command. The structure of this program is that any action with the application will be automatically saved in XML File. 

Implementation of saving changes to a file: with functions I made at xml_codes.cpp. They will be called with UNDO, REDO commands.Doesn't need to load file before beginning, loading happens automatically in the fxml().


