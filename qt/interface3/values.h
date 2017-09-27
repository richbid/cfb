#ifndef VALUES_H
#define VALUES_H

#include <QList>
#include <QDebug>

namespace onelab
{
    class Text
    {
    public:
        static QString to_hex(const QString& input);
        static QString from_hex(const QString& input);
        static QString to_md5(const QString& input);
        static QString to_base64(const QString& input);
        static QString from_base64(const QString& input);
    };

    class ISortable
    {
    public:
        virtual void sort(bool decending) = 0;
    };

    template <typename T>
    class Troop
    {
    private:
        bool mHasError;
        static bool equals(const Troop<T> &from, const Troop<T> &to);

    public:
        QList<T> data;
        Troop();
        T get(int index);
        bool set(int index, T value);
        void append(T value);
        bool insert(int index, T value);
        void appendRange(const QList<T>& range);
        bool insertRange(int index, const QList<T>& range);
        void clear();
        bool remove(int index);
        bool removeRange(int index, int count);
        int length() const;
        void enqueue(T value);
        T dequeue();
        void push(T value);
        T pop();
        bool getRange(int index, int count, Troop<T>& output);
        void reverse();
        bool swap(int index0, int index1);
        T take(int index);
        void rollForward(int offset);
        void rollBackward(int offset);
        bool operator==(const Troop& input) const;
        bool operator!=(const Troop& input) const;
        bool hasError() const;
        virtual QString toString();
        virtual int fromString(const QString& input);
    };

    class Variants : public Troop<QVariant>
    {
    public:
        //static void test();
        explicit Variants();
        explicit Variants(const QString& input);
        virtual QString toString() override;
        virtual int fromString(const QString& input) override;
    };

    class Bytes : public Troop<uchar>, public ISortable
    {
    public:
        //static void test();
        explicit Bytes();
        explicit Bytes(const QString& input);
        virtual QString toString() override;
        virtual int fromString(const QString& input) override;
        virtual void sort(bool decending) override;
    };

    using HashCodeType = unsigned int;
    
    template<typename T>
    class Node
    {
    private:
        static HashCodeType nextUid();
        HashCodeType mUid;
        
    public:
        HashCodeType uid();
        bool hit(Node<T>* item);
        T Value;
        Node<T>* Parent;
        Troop< Node<T>* > Children;
        Node<T>* next();
        Node<T>* previous();
        int indexOfChild(Node<T>* item);
        bool removeChild(int index);
        bool removeChild(Node<T>* item);
        Node<T>* appendChild(Node<T>* item);
        Node<T>* insertChild(int index, Node<T>* newItem);
        Node<T>* insertChild(Node<T>* item, Node<T>* newItem);
        Node(T value);        
        ~Node();
        static Node<T>* create(T value);
    };
}

void nodeInt32Test();

#endif // VALUES_H
