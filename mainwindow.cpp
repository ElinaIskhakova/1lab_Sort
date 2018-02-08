#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTextCodec>
#include<time.h>
#include<fstream>
#include <sort.h>
#include<string>
#define PATH "C:\\Users\\USER\\Documents\\1laba_sort\\text2.txt"
int srav=0, obmen=0;
int digit( int n, int p) {  // Получение p-го байта
    return (n >> (8 * p) & 255);
}

// Сортировка подсчётом массива a по p байту
void counting_sort ( int *a, int number, const int p) {
    // Максимальное число байтов в числе
     int* b = new  int[number];
    // У байта максимум 256 значений
    int c[256] = {0};
    // Подсчитываем количество элементов
    // в массиве соответствующий каждому
    // байту (из сортировок подсчетом)
    for ( int j = 0; j < number; ++j ) {
        c[digit(a[j],p)]++;
    }
    // Модифицируем массив с.
    // c[i] - номер элемента, следующего после i-го блока
    for ( int j = 1; j < 256; ++j ) {
        c[j] += c[j - 1];
    }
    // Cдвигаем массив
    for ( int j = number - 1; j >= 0; --j ) {
        b[--c[digit(a[j],p)]] = a[j];
    }
    for ( int j = 0; j < number; ++j ) {
        a[j] = b[j];
    }
    delete[] b;
}

// Сортировка массива  методом поразрядной сортировки LSD по байтам
 int*LSD_Sort(int *a, int number) {
     int max_size = sizeof(int);
    // Цикл по всем байтам
    for ( int i = 0; i < max_size; ++i ) {
        counting_sort(a, number, i);
    }
    return a;
}
void qsortRecursiveIN(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;
    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
            srav++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
            srav++;
        }
        //Меняем элементы местами
        if (i <= j) {
            obmen++;
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursiveIN(mas, j + 1);
    }
    if (i < size) {
        //"Правый кусок"
        qsortRecursiveIN(&mas[i], size - i);
    }
}

void qsortRecursiveDE(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;
    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {

        while(mas[i] > mid) {
            i++;
            srav++;
        }

        while(mas[j] < mid) {
            j--;
            srav++;
        }
        //Меняем элементы местами
        if (i <= j) {
            obmen++;
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursiveDE(mas, j + 1);
    }
    if (i < size) {
        //"Правый кусок"
        qsortRecursiveDE(&mas[i], size - i);
    }
}
void qsortRecursiveINFile(std::string *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;
    //Центральный элемент массива
    std::string mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
            srav++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
            srav++;
        }
        //Меняем элементы местами
        if (i <= j) {
            obmen++;
            std::string tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursiveINFile(mas, j + 1);
    }
    if (i < size) {
        //"Правый кусок"
        qsortRecursiveINFile(&mas[i], size - i);
    }
}

QStandardItemModel *model = new QStandardItemModel;
   QStandardItem *item;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1251"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
       //Заголовки столбцов
       QStringList horizontalHeader;
       horizontalHeader.append("Вид сортировки");
       horizontalHeader.append("Тип данных");
       horizontalHeader.append("Количество элементов");
       horizontalHeader.append("Количество сравнений");
        horizontalHeader.append("Количество перестановок");

       //Заголовки строк
       QStringList verticalHeader;
       verticalHeader.append("1");
       verticalHeader.append("2");
       verticalHeader.append("3");
       verticalHeader.append("4");

       model->setHorizontalHeaderLabels(horizontalHeader);
       model->setVerticalHeaderLabels(verticalHeader);

       //Первый ряд
       item = new QStandardItem(QString("Глупая"));
       model->setItem(0, 0, item);

       //Второй ряд
       item = new QStandardItem(QString("Двоичная"));
       model->setItem(1, 0, item);

        //Третий ряд
       item = new QStandardItem(QString("Нисходящая"));
       model->setItem(2, 0, item);
       //Четвертый ряд
      item = new QStandardItem(QString("Быстрая"));
      model->setItem(3, 0, item);

       ui->tableView->setModel(model);
       ui->tableView->resizeRowsToContents();
       ui->tableView->resizeColumnsToContents();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_5_clicked()
{

}


void MainWindow::on_FileButton_8_clicked()
{
    /*QFile file("C:\\Users\\USER\\Documents\\1laba_sort\\text.txt");
    if(!file.open(QIODevice::ReadOnly ))
QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
   ui->textBrowser->setText(in.readAll());*/
}

void MainWindow::on_pushButton_2_clicked()
{
      ui->textBrowser->clear();
      ui->textBrowser_2->clear();
}

void MainWindow::on_pushButton_clicked()
{ int size_array=100;
    ui->label_4->setText(QString::number(size_array));

    //Глупая сортировка чисел по возрастанию
    if((ui->StupidButton->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->NumberButton_7->isChecked()))
    {
        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );

             }
             clock_t start=clock();
           int i = 0, tmp, countSRAV=0, countOBMEN=0;

                       while (i < size_array - 1)
                       {
                           if (sorted_array[i + 1] < sorted_array[i])
                           { countSRAV++;//число сравнений
                               countOBMEN++;//число перестановок
                               tmp = sorted_array[i];
                              sorted_array[i] =sorted_array[i + 1];
                              sorted_array[i + 1] = tmp;
                               i = 0;
                           }
                           else i++;
                       }
                       clock_t end=clock();
                    float seconds=(float)(end-start)/CLOCKS_PER_SEC;
                    ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds,'f',10)+
                    "\nСреднее число сравнений: "+QString::number(countSRAV)+
                    "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < size_array; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                        }
                        delete [] sorted_array;
                        item = new QStandardItem(QString("массив чисел"));
                        model->setItem(0, 1, item);
                        item = new QStandardItem(QString::number(size_array));
                        model->setItem(0, 2, item);
                        item = new QStandardItem(QString::number(countSRAV));
                        model->setItem(0, 3, item);
                        item = new QStandardItem(QString::number(countOBMEN));
                        model->setItem(0, 4, item);

    }
    //Глупая сортировка чисел по убыванию
    if((ui->StupidButton->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->NumberButton_7->isChecked()))
    {

        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           int i = 0, tmp, countSRAV=0, countOBMEN=0;
            clock_t start=clock();
                       while (i < size_array - 1)
                       {
                           if (sorted_array[i + 1] > sorted_array[i])
                           {  countSRAV++;
                               countOBMEN++;
                               tmp = sorted_array[i];
                              sorted_array[i] =sorted_array[i + 1];
                              sorted_array[i + 1] = tmp;
                               i = 0;
                           }
                           else i++;
                       }
                       clock_t end=clock();
                    double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                    ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                    "\nСреднее число сравнений: "+QString::number(countSRAV)+
                     "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < size_array; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                        }
                        item = new QStandardItem(QString("массив чисел"));
                        model->setItem(0, 1, item);
                        item = new QStandardItem(QString::number(size_array));
                        model->setItem(0, 2, item);
                        item = new QStandardItem(QString::number(countSRAV));
                        model->setItem(0, 3, item);
                        item = new QStandardItem(QString::number(countOBMEN));
                        model->setItem(0, 4, item);
                        delete [] sorted_array;
    }
    //Быстрая сортировка чисел по возрастанию
    if((ui->QuickButton_4->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->NumberButton_7->isChecked()))
    {
        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           clock_t start=clock();
           qsortRecursiveIN(sorted_array, size_array);
           clock_t end=clock();
        double seconds=(double)(end-start)/CLOCKS_PER_SEC;
        ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds,'f',6)+
        "\nСреднее число сравнений: "+QString::number(srav)+
        "\nСреднее число перестановок: "+QString::number(obmen));
           QString r;
            for (int i = 0; i < size_array; i++)
              {
                r += QString::number( sorted_array[i])+" ";
                ui->textBrowser_2->setText(r );
            }
            item = new QStandardItem(QString("массив чисел"));
            model->setItem(3, 1, item);
            item = new QStandardItem(QString::number(size_array));
            model->setItem(3, 2, item);
            item = new QStandardItem(QString::number(srav));
            model->setItem(3, 3, item);
            item = new QStandardItem(QString::number(obmen));
            model->setItem(3, 4, item);
             delete [] sorted_array;

    }
    //Быстрая сортировка чисел по убыванию
    if((ui->QuickButton_4->isChecked())&&(ui->DecreaseButton_6->isChecked())
            &&(ui->NumberButton_7->isChecked()))
    {
        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           clock_t start=clock();
           qsortRecursiveDE(sorted_array, size_array);
           clock_t end=clock();
        double seconds=(double)(end-start)/CLOCKS_PER_SEC;

        ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds,'f',10)+
        "\nСреднее число сравнений: "+QString::number(srav)+
        "\nСреднее число перестановок: "+QString::number(obmen));
           QString r;
            for (int i = 0; i < size_array; i++)
              {
                r += QString::number( sorted_array[i])+" ";
                ui->textBrowser_2->setText(r );
            }
            item = new QStandardItem(QString("массив чисел"));
            model->setItem(3, 1, item);
            item = new QStandardItem(QString::number(size_array));
            model->setItem(3, 2, item);
            item = new QStandardItem(QString::number(srav));
            model->setItem(3, 3, item);
            item = new QStandardItem(QString::number(obmen));
            model->setItem(3, 4, item);
             delete [] sorted_array;

    }
    //Двоичная сортировка чисел по возрастанию
    if((ui->SortBinButton_2->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->NumberButton_7->isChecked()))
    {

        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
clock_t start=clock();
           int x, left, right, sred,countSRAV=0, countOBMEN=0;
           for (int i = 1;  i < size_array; i++)
               if ( sorted_array[i-1] >  sorted_array[i]){
                   countSRAV++;
                   x =  sorted_array[i];
                   left = 0;
                   right = i-1;
                   do {
                       sred = (left + right)/2;
                       if  ( sorted_array[sred] < x ) left = sred + 1;
                       else  right = sred - 1;
                   } while (left <= right);
                   for (int j = i-1; j>=left; j--)
                     {
                       countOBMEN++;
                        sorted_array[j+1] =  sorted_array[j];
                   }
                   sorted_array[left] = x;
                   clock_t end=clock();
                double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                "\nСреднее число сравнений: "+QString::number(countSRAV)+
                "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < size_array; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                          }
         }
           delete [] sorted_array;
           item = new QStandardItem(QString("массив чисел"));
           model->setItem(1, 1, item);
           item = new QStandardItem(QString::number(size_array));
           model->setItem(1, 2, item);
           item = new QStandardItem(QString::number(countSRAV));
           model->setItem(1, 3, item);
           item = new QStandardItem(QString::number(countOBMEN));
           model->setItem(1, 4, item);
            delete [] sorted_array;



    }
    //Двоичная сортировка чисел по убыванию
    if((ui->SortBinButton_2->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->NumberButton_7->isChecked()))
    {

        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           clock_t start=clock();
           int x, left, right, sred,countSRAV=0, countOBMEN=0;;
           for (int i = 1;  i < size_array; i++)
               if ( sorted_array[i-1] >  sorted_array[i]){
                   countSRAV++;
                   x =  sorted_array[i];
                   left = 0;
                   right = i-1;
                   do {
                       sred = (left + right)/2;
                       if  ( sorted_array[sred] > x ) left = sred + 1;
                       else  right = sred - 1;
                   } while (left <= right);
                   for (int j = i-1; j>=left; j--)
                     {
                       countOBMEN++;
                       sorted_array[j+1] =  sorted_array[j];
                     }
                   sorted_array[left] = x;
                   clock_t end=clock();
                double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                "\nСреднее число сравнений: "+QString::number(countSRAV)+
                "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < size_array; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                          }
         }
           item = new QStandardItem(QString("массив чисел"));
           model->setItem(1, 1, item);
           item = new QStandardItem(QString::number(size_array));
           model->setItem(1, 2, item);
           item = new QStandardItem(QString::number(countSRAV));
           model->setItem(1, 3, item);
           item = new QStandardItem(QString::number(countOBMEN));
           model->setItem(1, 4, item);
            delete [] sorted_array;

    }
    //Глупая сортировка записей по возрастанию
    if((ui->StupidButton->isChecked())&&(ui->IncreaseButton_5->isChecked())
            &&(ui->FileButton_8->isChecked()))
    {
        int j = 0,k=0;
        std::ifstream text(PATH);
        std::string *sorted_array = new std::string [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
        ui->label_4->setText(QString::number(k));
        QFile file1("C:\\Users\\USER\\Documents\\1laba_sort\\text2.txt");
            if(!file1.open(QIODevice::ReadOnly ))
        QMessageBox::information(0,"info",file1.errorString());
            QTextStream in(&file1);
           ui->textBrowser->setText(in.readAll());
         QString s;
      /*  for (int i = 0; i < k; i++)
          {

            s += QString::number( sorted_array[i])+" ";

          }*/

        clock_t start=clock();
      int i=0, countSRAV=0,countOBMEN=0;
      std::string tmp;

                  while (i < k- 1)
                  {
                      if (sorted_array[i + 1] < sorted_array[i])
                      { countSRAV++;//число сравнений
                          countOBMEN++;//число перестановок
                          tmp = sorted_array[i];
                         sorted_array[i] =sorted_array[i + 1];
                         sorted_array[i + 1] = tmp;
                          i = 0;
                      }
                      else i++;
                  }
                  clock_t end=clock();

               double seconds=(double)(end-start)/CLOCKS_PER_SEC;
               ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
               "\nСреднее число сравнений: "+QString::number(countSRAV)+
               "\nСреднее число перестановок: "+QString::number(countOBMEN));
                  QString t;
                  std::ofstream f_of ("C:\\Users\\USER\\Documents\\1laba_sort\\textStupid.txt");
                             for (int i = 0; i < size_array; i++)
                             {
                                 f_of << sorted_array[i] << "\n";
                             }
                             QFile fileStupid("C:\\Users\\USER\\Documents\\1laba_sort\\textStupid.txt");
                                         if (!fileStupid.open(QIODevice::ReadOnly))
                                             QMessageBox::information(0, "info", fileStupid.errorString());
                                         QTextStream in1(&fileStupid);
                                         ui->textBrowser_2->setText((in1.readAll()));
                  /* for (int i = 0; i < k; i++)
                     {
                       t += QString::number( sorted_array[i])+" ";
                       ui->textBrowser_2->setText(t );
                   }*/
                   item = new QStandardItem(QString("массив записей"));
                   model->setItem(0, 1, item);
                   item = new QStandardItem(QString::number(k));
                   model->setItem(0, 2, item);
                   item = new QStandardItem(QString::number(countSRAV));
                   model->setItem(0, 3, item);
                   item = new QStandardItem(QString::number(countOBMEN));
                   model->setItem(0, 4, item);
                    delete [] sorted_array;

    }
    //Глупая сортировка записей по убыванию
    if((ui->StupidButton->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->FileButton_8->isChecked()))
    {
        int j = 0,k=0;
        std::ifstream text(PATH);
        std::string *sorted_array = new std::string [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
        ui->label_4->setText(QString::number(k));
        QFile file1("C:\\Users\\USER\\Documents\\1laba_sort\\text2.txt");
            if(!file1.open(QIODevice::ReadOnly ))
        QMessageBox::information(0,"info",file1.errorString());
            QTextStream in(&file1);
           ui->textBrowser->setText(in.readAll());
        /* QString s;
        for (int i = 0; i < k; i++)
          {
            s += QString::number( sorted_array[i])+" ";
               ui->textBrowser->setText(s );
          }*/
           int i = 0,countSRAV=0, countOBMEN=0;
           std::string tmp;
            clock_t start=clock();
                       while (i < k - 1)
                       {
                           if (sorted_array[i + 1] > sorted_array[i])
                           {  countSRAV++;
                               countOBMEN++;
                               tmp = sorted_array[i];
                              sorted_array[i] =sorted_array[i + 1];
                              sorted_array[i + 1] = tmp;
                               i = 0;
                           }
                           else i++;
                       }
                       clock_t end=clock();
                    double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                    ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                    "\nСреднее число сравнений: "+QString::number(countSRAV)+
                     "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < k; i++)
                          {
                            t += QString::fromStdString( sorted_array[i]);
                            ui->textBrowser_2->setText(t );
                        }
                    std::ofstream f_of ("C:\\Users\\USER\\Documents\\1laba_sort\\textStupid1.txt");
                               for (int i = 0; i < size_array; i++)
                               {
                                   f_of << sorted_array[i] << "\n";
                               }
                               QFile fileStupid("C:\\Users\\USER\\Documents\\1laba_sort\\textStupid1.txt");
                                           if (!fileStupid.open(QIODevice::ReadOnly))
                                               QMessageBox::information(0, "info", fileStupid.errorString());
                                           QTextStream in1(&fileStupid);
                                           ui->textBrowser_2->setText((in1.readAll()));
                        item = new QStandardItem(QString("массив записей"));
                        model->setItem(0, 1, item);
                        item = new QStandardItem(QString::number(k));
                        model->setItem(0, 2, item);
                        item = new QStandardItem(QString::number(countSRAV));
                        model->setItem(0, 3, item);
                        item = new QStandardItem(QString::number(countOBMEN));
                        model->setItem(0, 4, item);
                         delete [] sorted_array;
    }
    //Быстрая сортировка записей по возрастанию
    if((ui->QuickButton_4->isChecked())&&(ui->IncreaseButton_5->isChecked())
            &&(ui->FileButton_8->isChecked()))
    {
        int j = 0,k=0;
        std::ifstream text(PATH);
        std::string *sorted_array = new std::string [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
       /* QString s;
       for (int i = 0; i < k; i++)
         {
           s += QString::number( sorted_array[i])+" ";
              ui->textBrowser->setText(s);
         }*/
        QFile file1("C:\\Users\\USER\\Documents\\1laba_sort\\text2.txt");
            if(!file1.open(QIODevice::ReadOnly ))
        QMessageBox::information(0,"info",file1.errorString());
            QTextStream in(&file1);
           ui->textBrowser->setText(in.readAll());
        ui->label_4->setText(QString::number(k));
        item = new QStandardItem(QString("массив записей"));
        model->setItem(3, 1, item);
        item = new QStandardItem(QString::number(k));
        model->setItem(3, 2, item);
        clock_t start=clock();
        qsortRecursiveINFile(sorted_array, k);
        clock_t end=clock();
     double seconds=(double)(end-start)/CLOCKS_PER_SEC;

     ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds,'f',8)+
     "\nСреднее число сравнений: "+QString::number(srav)+
     "\nСреднее число перестановок: "+QString::number(obmen));
           /*QString r;
            for (int i = 0; i < k; i++)
              {
                r += QString::number( sorted_array[i])+" ";
                ui->textBrowser_2->setText(r );
            }*/
     std::ofstream f_of ("C:\\Users\\USER\\Documents\\1laba_sort\\textQuick.txt");
                for (int i = 0; i < k; i++)
                {
                    f_of << sorted_array[i] << "\n";
                }
               /* QFile fileQuick("C:\\Users\\USER\\Documents\\1laba_sort\\textQuick.txt");
                            if (!fileQuick.open(QIODevice::ReadOnly))
                                QMessageBox::information(0, "info", fileQuick.errorString());
                            QTextStream in1(&fileQuick);
                            ui->textBrowser_2->setText(in1.readAll());*/
                QFile file2("C:\\Users\\USER\\Documents\\1laba_sort\\textQuick.txt");
                    if(!file2.open(QIODevice::ReadOnly ))
                QMessageBox::information(0,"info",file2.errorString());
                    QTextStream in1(&file2);
                   ui->textBrowser_2->setText(in1.readAll());
            item = new QStandardItem(QString("массив записей"));
            model->setItem(3, 1, item);
            item = new QStandardItem(QString::number(k));
            model->setItem(3, 2, item);
            item = new QStandardItem(QString::number(srav));
            model->setItem(3, 3, item);
            item = new QStandardItem(QString::number(obmen));
            model->setItem(3, 4, item);
             delete [] sorted_array;

    }
    //Быстрая сортировка записей по убыванию
    if((ui->QuickButton_4->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->FileButton_8->isChecked()))
    {int j = 0,k=0;
        std::ifstream text(PATH);
        int *sorted_array = new int [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
        QString s;
       for (int i = 0; i < k; i++)
         {
           s += QString::number( sorted_array[i])+" ";
              ui->textBrowser->setText(s);
         }
        item = new QStandardItem(QString("массив записей"));
        model->setItem(3, 1, item);
        item = new QStandardItem(QString::number(k));
        model->setItem(3, 2, item);

           clock_t start=clock();
           qsortRecursiveDE(sorted_array, k);
           clock_t end=clock();
        double seconds=(double)(end-start)/CLOCKS_PER_SEC;

        ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
        "\nСреднее число сравнений: "+QString::number(srav)+
        "\nСреднее число перестановок: "+QString::number(obmen));
           QString r;
            for (int i = 0; i <k; i++)
              {
                r += QString::number( sorted_array[i])+" ";
                ui->textBrowser_2->setText(r );
            }
            item = new QStandardItem(QString("массив записей"));
            model->setItem(3, 1, item);
            item = new QStandardItem(QString::number(k));
            model->setItem(3, 2, item);
            item = new QStandardItem(QString::number(srav));
            model->setItem(3, 3, item);
            item = new QStandardItem(QString::number(obmen));
            model->setItem(3, 4, item);
             delete [] sorted_array;

    }
    //Двоичная сортировка записей по возрастанию
    if((ui->SortBinButton_2->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->FileButton_8->isChecked()))
    {
        int j = 0,k=0,countSRAV=0, countOBMEN=0;;
        std::ifstream text(PATH);
        int *sorted_array = new int [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
        QString s;
       for (int i = 0; i < k; i++)
         {
           s += QString::number( sorted_array[i])+" ";
              ui->textBrowser->setText(s);
         }
        ui->label_4->setText(QString::number(k));
        item = new QStandardItem(QString("массив записей"));
        model->setItem(1, 1, item);
        item = new QStandardItem(QString::number(k));
        model->setItem(1, 2, item);

clock_t start=clock();
           int x, left, right, sred;
           for (int i = 1;  i < k; i++)
               if ( sorted_array[i-1] >  sorted_array[i]){
                   countSRAV++;
                   x =  sorted_array[i];
                   left = 0;
                   right = i-1;
                   do {
                       sred = (left + right)/2;
                       if  ( sorted_array[sred] < x ) left = sred + 1;
                       else  right = sred - 1;
                   } while (left <= right);
                   for (int j = i-1; j>=left; j--)
                   {
                       countOBMEN++;
                        sorted_array[j+1] =  sorted_array[j];
                   }
                   sorted_array[left] = x;
                   clock_t end=clock();
                double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                "\nСреднее число сравнений: "+QString::number(countSRAV)+
                "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i < k; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                          }
         }
           item = new QStandardItem(QString("массив записей"));
           model->setItem(1, 1, item);
           item = new QStandardItem(QString::number(k));
           model->setItem(1, 2, item);
           item = new QStandardItem(QString::number(countSRAV));
           model->setItem(1, 3, item);
           item = new QStandardItem(QString::number(countOBMEN));
           model->setItem(1, 4, item);
            delete [] sorted_array;

    }
    //Двоичная сортировка записей по убыванию
    if((ui->SortBinButton_2->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->FileButton_8->isChecked()))
    {
        int j = 0,k=0,countSRAV=0, countOBMEN=0;
        std::ifstream text(PATH);
        int *sorted_array = new int [size_array]; // одномерный динамический массив

        while(!text.eof())
        {
            text >> sorted_array[j];
            j++;
            k++;
        }
        QString s;
       for (int i = 0; i < k; i++)
         {
           s += QString::number( sorted_array[i])+" ";
              ui->textBrowser->setText(s);
         }

           clock_t start=clock();
           int x, left, right, sred;
           for (int i = 1;  i < k; i++)
               if ( sorted_array[i-1] >  sorted_array[i]){
                   countSRAV++;
                   x =  sorted_array[i];
                   left = 0;
                   right = i-1;
                   do {
                       sred = (left + right)/2;
                       if  ( sorted_array[sred] > x ) left = sred + 1;
                       else  right = sred - 1;
                   } while (left <= right);
                   for (int j = i-1; j>=left; j--)
                   {
                       countOBMEN++;
                        sorted_array[j+1] =  sorted_array[j];
                   }
                   sorted_array[left] = x;
                   clock_t end=clock();
                double seconds=(double)(end-start)/CLOCKS_PER_SEC;

                ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds)+
                "\nСреднее число сравнений: "+QString::number(countSRAV)+
                "\nСреднее число перестановок: "+QString::number(countOBMEN));
                       QString t;
                        for (int i = 0; i <k; i++)
                          {
                            t += QString::number( sorted_array[i])+" ";
                            ui->textBrowser_2->setText(t );
                          }
         }
           item = new QStandardItem(QString("массив записей"));
           model->setItem(1, 1, item);
           item = new QStandardItem(QString::number(k));
           model->setItem(1, 2, item);
           item = new QStandardItem(QString::number(countSRAV));
           model->setItem(1, 3, item);
           item = new QStandardItem(QString::number(countOBMEN));
           model->setItem(1, 4, item);
            delete [] sorted_array;

    }

    //Нисходящая чисел по возрастанию
    if((ui->MergeButton_3->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->NumberButton_7->isChecked()))
    {
        int *sorted_array = new int [size_array]; // одномерный динамический массив
          QString s;
           for (int i = 0; i < size_array; i++)
             {  sorted_array[i] = rand() % 100; // заполняем массив случайными числами
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           clock_t start=clock();
          sorted_array = LSD_Sort(sorted_array, size_array);
           clock_t end=clock();
        double seconds=(double)(end-start)/CLOCKS_PER_SEC;
        QString t;
         for (int i = 0; i < size_array; i++)
           {
             t += QString::number( sorted_array[i])+" ";
             ui->textBrowser_2->setText(t );
         }
          delete [] sorted_array;
      ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds));/*+
        "\nСреднее число сравнений: "+QString::number(srav)+
        "\nСреднее число перестановок: "+QString::number(obmen));*/
       delete [] sorted_array;
    }
   //Нисходящая чисел по убыванию
    if((ui->MergeButton_3->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->NumberButton_7->isChecked()))
   {
       int *sorted_array = new int [size_array]; // одномерный динамический массив
       QString s;
       for (int i = 0; i < size_array; i++)
        {
           sorted_array[i] = rand() % 100; // заполняем массив случайными числами
           s += QString::number( sorted_array[i])+" ";
           ui->textBrowser->setText(s );
        }
    }
    //Нисходящая сортировка записей по возрастанию
       if((ui->MergeButton_3->isChecked())&&(ui->IncreaseButton_5->isChecked())&&(ui->FileButton_8->isChecked()))
       {
           int j = 0,k=0;
           std::ifstream text(PATH);
           int *sorted_array = new int [size_array]; // одномерный динамический массив

           while(!text.eof())
           {
               text >> sorted_array[j];
               j++;
               k++;
           }
           ui->label_4->setText(QString::number(k));
            QString s;
           for (int i = 0; i < k; i++)
             {
               s += QString::number( sorted_array[i])+" ";
                  ui->textBrowser->setText(s );
             }
           clock_t start=clock();
          sorted_array = LSD_Sort(sorted_array,k);
           clock_t end=clock();
        double seconds=(double)(end-start)/CLOCKS_PER_SEC;
        QString t;
         for (int i = 0; i <k; i++)
           {
             t += QString::number( sorted_array[i])+" ";
             ui->textBrowser_2->setText(t );
         }
          delete [] sorted_array;
      ui->textBrowser_3->setText("Время сортировки: "+QString::number(seconds));

       }
   //Нисходящая сортировка записей по убыванию
      if((ui->MergeButton_3->isChecked())&&(ui->DecreaseButton_6->isChecked())&&(ui->FileButton_8->isChecked()))
       {
         int j = 0,k=0;
         std::ifstream text(PATH);
         int *sorted_array = new int [size_array]; // одномерный динамический массив
          while(!text.eof())
          {
             text >> sorted_array[j];
             j++;
             k++;
          }
            ui->label_4->setText(QString::number(k));
            QString s;
            for (int i = 0; i < k; i++)
             {
               s += QString::number( sorted_array[i])+" ";
               ui->textBrowser->setText(s );
             }

         delete [] sorted_array;
     }

}




