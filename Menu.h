#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <Windows.h>
#include "Management.h"
#include "ManagementConsolHelper.h"

void Print()
{
    ManagementConsol console;
    int choice;

    do {
        cout << "\n========== МНОГОДОКУМЕНТНЫЙ РЕДАКТОР ==========\n";
        cout << "1. Создать новый документ\n";
        cout << "2. Открыть документ\n";
        cout << "3. Сохранить текущий документ\n";
        cout << "4. Сохранить текущий документ как...\n";
        cout << "5. Показать все документы\n";
        cout << "6. Переключиться на другой документ\n";
        cout << "7. ПЕЧАТЬ текущего документа\n";    // ? НОВЫЙ ПУНКТ
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: console.createManagementConsol(); break;
        case 2: console.OpenManagementConsol(); break;
        case 3: console.saveCurrentDocument(); break;
        case 4: console.SaveAsNewCurrentDocument(); break;
        case 5: console.showAllDocuments(); break;
        case 6: console.switchDocument(); break;
        case 7: console.Printing_DocManagementConsol(); break;    // ? НОВЫЙ ВЫЗОВ
        case 0: cout << "До свидания!" << endl; break;
        default: cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}