#pragma once

#include "Node.h"

class Tree
{
private:

    // Корень.
    Node* m_root;

    // Количество узлов.
    unsigned int m_size;

public:

    Tree();

    ~Tree();
    
    // Получить корень.
    Node* GetRoot() const;
    
    // Вставка узла.
    void Insert(Node* node);

    // Максимальное значение от указанного узла.
    Node* Max(Node* node) const;

    // Минимальное значение от указанного узла.
    Node* Min(Node* node) const;

    // Следующий узел для указанного узла.
    Node* Next(const Node* node) const;

    // Предыдущий узел для указанного узла.
    Node* Previous(const Node* node) const;

    // Печать от указанного узла.
    void Print(const Node* node) const;

    // Удаление ветки для указанного узла.
    void Remove(Node* node);

    // Поиск от указанного узла.
    Node* Search(Node* node, const char* key) const;
};