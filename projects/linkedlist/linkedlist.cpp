#include <iostream>
#include <vector>

template <class T>
class List
{
        class Node
        {
                T value;
                Node *next;
                Node *previous;
		public:
                Node(const T &v) : value(v), next(0), previous(0) {}

                ~Node() {}

                friend class List;
        };

        Node *head;
        Node *tail;

public:
        List() : head(0), tail(0) {}

        List(const T &v) : head(0), tail(0)
        {
                Node *first;

                first = new Node(v);

                head = tail = first;
        }
        List(const std::vector<T> &vec) : head(0), tail(0)
        {
                size_t i;
                Node *newNode;
                Node *tmp;
                Node *current;

                if (vec.empty())
                        return;

                head = new Node(vec[0]);

                current = tail = head;

                for (i = 1; i < vec.size(); i++)
                {
                        newNode = new Node(vec[i]);
                        tmp = current;
                        current->next = newNode;
                        tail = current = current->next;
                        current->previous = tmp;
                }
        }

        ~List()
        {
                Node *current;
                Node *next;

                current = head;

                while (current)
                {
                        next = current->next;
                        delete current;
                        current = next;
                }

                head = tail = 0;
        }

        void push(const T &v)
        {
                Node *newHead = new Node(v);

                if (!head)
                {
                        head = tail = newHead;
                        return;
                }

                newHead->next = head;
                head->previous = newHead;
                head = newHead;
        }

        void append(const T &v)
        {
                Node *newTail;

                newTail = new Node(v);

                if (!tail)
                {
                        head = tail = newTail;
                        return;
                }

                newTail->previous = tail;
                tail->next = newTail;
                tail = newTail;
        }

        T pop()
        {
                Node *oldHead;
                T value;

                if (!head)
                        return T();

                if (head->next == 0)
                {
                        value = head->value;
                        delete head;
                        tail = head = 0;
                        return value;
                }

                oldHead = head;

                value = head->value;

                head = head->next;

                head->previous = 0;

                delete oldHead;

                return value;
        }

        T detach()
        {
                T value;
                Node *oldTail;

                if (!tail)
                        return T();

                if (tail->previous == 0)
                {
                        value = tail->value;
                        delete tail;
                        head = tail = 0;
                        return value;
                }

                value = tail->value;

                oldTail = tail;

                tail = tail->previous;

                tail->next = 0;

                delete oldTail;

                return value;
        }

        class Iterator
        {
                Node *current;

        public:
                Iterator(Node *node) : current(node) {}
                T &operator*() { return current->value; }

                Iterator &operator++()
                {
                        current = current->next;
                        return *this;
                }

                Iterator operator++(int)
                {
                        Iterator tmp = *this;
                        current = current->next;
                        return tmp;
                }

                Iterator &operator--()
                {
                        current = current->previous;
                        return *this;
                }

                Iterator operator--(int)
                {
                        Iterator tmp = *this;
                        current = current->previous;
                        return tmp;
                }

                bool operator!=(const Iterator &other) const { return current != other.current; }
                bool operator==(const Iterator &other) const { return current == other.current; }
        };

        Iterator begin() { return Iterator(head); }
        Iterator end() { return Iterator(0); }
};
