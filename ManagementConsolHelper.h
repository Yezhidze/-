#pragma once
#include <iostream>
#include <string>
#include "Management.h"
#include <vector>
using namespace std;

class ManagementConsol
{
private:
    vector<Management*> documents;
    int currentDoc;
public:
    ManagementConsol() : currentDoc(-1) {}
    ~ManagementConsol()
    {
        for (auto doc : documents)
            delete doc;
    }
    void createManagementConsol()
    {
        string fileName;
        cout << "Введите имя файла для создания: ";
        cin >> fileName;

        Management* newDoc = new Management(fileName);
        if (newDoc->create())
        {
            documents.push_back(newDoc);
            currentDoc = documents.size() - 1;
            cout << "Документ создан: " << fileName << endl;
            cout << "Всего документов: " << documents.size() << endl;
        }
        else { delete newDoc; cout << "Ошибка создания!" << endl; }
    }

    void OpenManagementConsol()
    {
        string fileName;
        cout << "Введите имя файла для открытия: ";
        cin >> fileName;

        for (int i = 0; i < documents.size(); i++)
        {
            if (documents[i]->getName() == fileName)
            {
                currentDoc = i;
                cout << "Документ уже открыт: " << fileName << endl;
                return;
            }
        }
        Management* newDoc = new Management(fileName);
        if (newDoc->open())
        {
            documents.push_back(newDoc);
            currentDoc = documents.size() - 1;
            cout << "Документ открыт: " << fileName << endl;
            cout << "Всего документов: " << documents.size() << endl;
        }
        else { delete newDoc; cout << "Ошибка открытия: " << fileName << endl; }
    }

    void saveCurrentDocument()
    {
        if (documents.empty())
        {
            cout << "Нет открытых документов для сохранения!" << endl;
            return;
        }

        if (currentDoc >= 0 && currentDoc < documents.size())
        {
            if (documents[currentDoc]->Save())
            {
                cout << "Документ сохранён: " << documents[currentDoc]->getName() << endl;
            }
            else { cout << "? Ошибка сохранения!" << endl; }
        }
        else { cout << "? Нет активного документа!" << endl; }
    }

    void showAllDocuments()
    {
        if (documents.empty())
        {
            cout << "Нет открытых документов!" << endl;
            return;
        }

        cout << "\n=== Список документов ===" << endl;
        for (int i = 0; i < documents.size(); i++)
        {
            cout << i << ". " << documents[i]->getName();
            if (i == currentDoc) cout << " [АКТИВЕН]";
            cout << endl;
        }
    }

    void switchDocument()
    {
        if (documents.empty())
        {
            cout << "Нет документов для переключения!" << endl;
            return;
        }
        showAllDocuments();
        int index;
        cout << "Выберите индекс документа: ";
        cin >> index;

        if (index >= 0 && index < documents.size())
        {
            currentDoc = index;
            cout << "Текущий документ: " << documents[currentDoc]->getName() << endl;
        }
        else { cout << "Неверный индекс!" << endl; };
    }
    void SaveAsNewCurrentDocument()
    {
        if (documents.empty())
        {
            cout << "Нет открытых документов для сохранения!" << endl;
            return;
        }

        if (currentDoc >= 0 && currentDoc < documents.size())
        {
            string newName;
            cout << "Введите новое имя файла: ";
            cin >> newName;
            if (documents[currentDoc]->SaveAsNew(newName))
            {
                cout << "Документ сохранён: " << documents[currentDoc]->getName() << endl;
            }
            else { cout << "Ошибка сохранения!" << endl; }
        }
        else { cout << "Нет документа!" << endl; }
    }
    void Printing_DocManagementConsol()
    {
        string fileName;
        cout << "Введите имя файла для открытия: ";
        cin >> fileName;

        for (int i = 0; i < documents.size(); i++)
        {
            if (documents[i]->getName() == fileName)
            {
                currentDoc = i;
                cout << "Документ уже открыт: " << fileName << endl;
                return;
            }
        }
        Management* newDoc = new Management(fileName);
        if (newDoc->open())
        {
            documents.push_back(newDoc);
            currentDoc = documents.size() - 1;
            cout << "Документ открыт: " << fileName << endl;
            cout << "Всего документов: " << documents.size() << endl;
        }
        else { delete newDoc; cout << "Ошибка открытия: " << fileName << endl; }
    }

};






