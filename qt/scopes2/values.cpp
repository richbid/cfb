#include "values.h"
#include <QStringList>
#include <QDateTime>
#include <QCryptographicHash>

namespace onelab
{
const char* datetime_format = "yyyyMMddHHmmsszzz";
const char* date_format = "yyyyMMdd";
const char* time_format = "HHmmsszzz";

const char* datetime_present_format = "yyyy-MM-dd HH:mm:ss.zzz";
const char* date_present_format = "yyyy-MM-dd";
const char* time_present_format = "HH:mm:ss.zzz";

template<typename T>
bool ascSorter(const T &v1, const T &v2)
{
    return v1 < v2;
}

template<typename T>
bool descSorter(const T &v1, const T &v2)
{
    return v1 > v2;
}   

template <typename T>
bool Troop<T>::equals(const Troop<T> &from, const Troop<T> &to)
{
    int len = from.length();
    if (len == to.length())
    {
        for (int n = 0; n < len; n++)
        {
            if (from.data[n] != to.data[n])
                return false;
        }                
        return true;
    }
    return false;    
}

template <typename T>
Troop<T>::Troop()
{
    mHasError = false;
}

template <typename T>
T Troop<T>::get(int index)
{
    mHasError = false;
    if (index >= 0 && index < data.length())
        return data[index];
    mHasError = true;
    return (T)0;        
}

template <typename T>
bool Troop<T>::set(int index, T value)
{
    if (index >= 0 && index < data.length())
    {
        data[index] = value;
        return true;
    }
    return false;        
}

template <typename T>
void Troop<T>::append(T value)
{
    data.append(value);
}

template <typename T>
bool Troop<T>::insert(int index, T value)
{
    if (index >= 0 && index < data.length())
    {
        data.insert(index, value);
        return true;
    }
    return false;        
}

template <typename T>
void Troop<T>::appendRange(const QList<T> &range)
{
    data.append(range);
}

template <typename T>
bool Troop<T>::insertRange(int index, const QList<T> &range)
{
    int length = data.length();
    if (index >= 0 && index < length)
    {
        QList<T> left = data.mid(0, index);
        QList<T> right = data.mid(index, -1);
        left.append(range);
        data.clear();
        data.append(left);
        data.append(right);
        return true;
    }
    return false;        
}

template <typename T>
void Troop<T>::clear()
{
    data.clear();
}

template <typename T>
bool Troop<T>::remove(int index)
{
    if (index >= 0 && index < data.length())
    {
        data.removeAt(index);
        return true;
    }
    return false;        
}

template <typename T>
bool Troop<T>::removeRange(int index, int count)
{
    if (count > 0 && index >= 0 && ((index + count) <= data.length()))
    {
        for (int n = 0; n < count; n++)
            data.removeAt(index);
        return true;
    }
    return false;        
}

template <typename T>
int Troop<T>::length() const
{
    return data.length();
}

template <typename T>
void Troop<T>::enqueue(T value)
{
    data.insert(0, value);
}

template <typename T>
T Troop<T>::dequeue()
{
    mHasError = false;
    int length = data.length();
    if (length > 0)
    {
        T b = data[length - 1];
        data.removeAt(length - 1);
        return b;
    }
    mHasError = true;
    return (T)0;        
}

template <typename T>
void Troop<T>::push(T value)
{
    data.append(value);
}

template <typename T>
T Troop<T>::pop()
{
    return dequeue();
}

template <typename T>
bool Troop<T>::getRange(int index, int count, Troop<T>& output)
{
    mHasError = true;
    if (count > 0 && index >= 0 && ((index + count) <= data.length()))
    {
        output.data = data.mid(index, count);
        mHasError = false;
    }
    return mHasError;  
}

template <typename T>
void Troop<T>::reverse()
{
    int length = data.length();
    QList<T> newData;
    for (int n = length - 1; n >= 0; n--)
        newData.append(data[n]);
    
    data.clear();
    data = newData;        
}

template <typename T>
bool Troop<T>::swap(int index0, int index1)
{
    int length = data.length();
    if (index0 >= 0 && index0 < length && index1 >= 0 && index1 < length)
    {
        T v = data[index0];
        data[index0] = data[index1];
        data[index1] = v;
        return true;
    }
    return false;
}

template <typename T>
T Troop<T>::take(int index)
{
    mHasError = false;
    if (index >= 0 && index < data.length())        
    {
        T v = data[index];
        data.removeAt(index);
        return v;
    }
    mHasError = true;
    return (T)0;
}

template <typename T>
void Troop<T>::rollForward(int offset)
{
    if (offset >= data.length()) return;
    QList<T> left = data.mid(offset - 1, -1);
    QList<T> right = data.mid(0, offset - 1);
    data.clear();
    data.append(left);
    data.append(right);
}

template <typename T>
void Troop<T>::rollBackward(int offset)
{
    if (offset >= data.length()) return;
    QList<T> left = data.mid(offset, -1);
    QList<T> right = data.mid(0, offset);        
    data.clear();
    data.append(left);
    data.append(right);
}

template <typename T>
bool Troop<T>::operator!=(const Troop& input) const
{
    return !equals(input, *this);
}

template<typename T>
bool Troop<T>::hasError() const
{
    return mHasError;    
}

template<typename T>
QString Troop<T>::toString()
{
    return QString();    
}

template<typename T>
int Troop<T>::fromString(const QString&)
{
    return 0;    
}

template <typename T>
bool Troop<T>::operator==(const Troop& input) const
{
    return equals(input, *this);
}

QString Variants::toString()
{
    QVariant::Type type;
    QStringList sb;
    foreach(QVariant ch, data)
    {
        type = ch.type();
        QString typeStr = QString::number(int(type), 16);
        if (typeStr.length() == 1)
            typeStr = "0" + typeStr;
        switch (type)
        {
        case QVariant::DateTime:
            sb << typeStr + ch.toDateTime().toString(datetime_format).toUtf8().toHex();
            break;
        case QVariant::Date:
            sb << typeStr + ch.toDate().toString(date_format).toUtf8().toHex();
            break;
        case QVariant::Time:
            sb << typeStr + ch.toTime().toString(time_format).toUtf8().toHex();
            break;
        default:
            sb << typeStr + ch.toString().toUtf8().toHex();
            break;
        }        
    }
    QString result = QString('(') + sb.join(QString(',')) + QString(')');
    return result;    
}

int Variants::fromString(const QString &input)
{
    int len = input.length();
    QString s, s2;
    QList<QVariant> list;
    int typeId;
    QVariant v;
    QVariant::Type type;
    if (!input.startsWith('(') && !input.endsWith(')')) return 0;
    for (int n = 1; n < len; n++)
    {
        s = input.mid(n, 1);
        if (s != "," && s != ")")
            s2 += s;
        else
        {
            int len2 = s2.length();
            if (len2 > 2 && !(len2 % 2))
            {
                typeId = s2.mid(0, 2).toInt(0, 16);
                if (typeId >= int(QVariant::UserType))
                    return 0;
                type = QVariant::Type(typeId);
                s2 = QByteArray::fromHex(s2.mid(2).toUtf8());
                switch(type)
                {
                case QVariant::DateTime:                    
                    v = QDateTime::fromString(s2, datetime_format);
                    break;
                case QVariant::Date:
                    v = QDate::fromString(s2, date_format);
                    break;
                case QVariant::Time:
                    v = QDate::fromString(s2, time_format);
                    break;
                default:
                    v = QVariant(s2);
                    break;
                }                
                list << v;
            }
            else
                return 0;
            s2.clear();
        }        
    }
    data = list;
    return 1;    
}

//void Variants::test()
//{
//    QString s;
//    Variants values;
//    values.append(QDateTime::currentDateTime());
//    values.append(3), values.append("H2O"), values.append(true), values.append(-1.3f), values.append(3.141692678);
//    s = values.toString();
//    qDebug() << "s = t.append(t.append(3), t.append(\"H2O\"), t.append(true), t.append(-1.3f), t.append(3.141692678)" << s;
//    values.clear();
//    qDebug() << "t.clear()" << values.toString();
//    values.fromString(s);
//    QString line;
//    foreach(QVariant v, values.data)
//    {
//        switch (v.type())
//        {
//        case QVariant::DateTime:
//            line += v.toDateTime().toString(datetime_present_format) + " ";
//            break;
//        case QVariant::Date:
//            line += v.toDate().toString(date_present_format) + " ";
//            break;
//        case QVariant::Time:
//            line += v.toTime().toString(time_present_format) + " ";
//            break;
//        default:
//            line += v.toString() + " ";
//            break;
//        }        
//    }
//    qDebug() << "t.fromString(s), data =" << line;
//}

Variants::Variants() : Troop<QVariant>()
{
    
}

Variants::Variants(const QString &input) : Troop<QVariant>()
{
    fromString(input);
}

Bytes::Bytes() : Troop<uchar>()
{
}

Bytes::Bytes(const QString &input) : Troop<uchar>()
{
    fromString(input);
}

//void Bytes::test()
//{
//    uchar last;
//    Bytes bytes2("(11,13,15)");
//    qDebug() << "bytes2(11,13,15)" << bytes2.toString();
//    Bytes bytes3("(12,14,16)");
//    qDebug() << "bytes3(12,14,16)" << bytes3.toString();
//    Bytes bytes;
//    bytes.fromString("(1,3,5,7,9)");
//    qDebug() << "bytes.fromString(1,3,5,7,9)" << bytes.toString();
//    bytes.insert(1, 4);
//    qDebug() << "bytes.insert(1, 4)" << bytes.toString();
//    bytes.append(2);
//    qDebug() << "bytes.append(2)" << bytes.toString();
//    bytes.insertRange(0, bytes2.data);
//    qDebug() << "bytes.insertRange(0, bytes2.data)" << bytes.toString();
//    bytes.appendRange(bytes3.data);
//    qDebug() << "bytes.appendRange(bytes3.data)" << bytes.toString();
//    bytes.enqueue(100);
//    qDebug() << "bytes.enqueue(100)" << bytes.toString();
//    last = bytes.dequeue();    
//    qDebug() << "last = bytes.dequeue()" << last;
//    bytes.push(101);
//    qDebug() << "bytes.push(101)" << bytes.toString();
//    last = bytes.pop();
//    qDebug() << "last = bytes.pop()" << last << bytes.toString();
//    bytes.removeRange(1, 3);
//    qDebug() << "bytes.removeRange(1, 3)" << bytes.toString();
//    bytes.set(1, 255);
//    qDebug() << "bytes.set(1, 255)" << bytes.toString();
//    for (int n = 0; n < bytes.length(); n++)
//        qDebug() << "bytes[" << n << "] =" << bytes.get(n);
//    bytes.getRange(2, 4, bytes);
//    qDebug() << "getRange(2, 4)" << bytes.toString();
//    bytes.sort(true);
//    qDebug() << "bytes.sort(true)" << bytes.toString();
//    for (int n = 0; n < bytes.length(); n++)
//        qDebug() << "bytes[" << n << "] =" << bytes.get(n);
//    bytes.clear();
//    qDebug() << "bytes.clear(), bytes.count =" << bytes.length();
    
//    uchar b;
//    bytes.fromString("(1,3,5,7,9)");
//    qDebug() << "bytes.fromString(1,3,5,7,9)" << bytes.toString();
//    bytes.rollForward(3);
//    qDebug() << "bytes.rollForward(3)" << bytes.toString();
//    b = bytes.take(2);
//    qDebug() << "bytes.take(2)" << b << bytes.toString();
//    bytes.fromString("(2,4,6,8,10)");
//    qDebug() << "bytes.fromString(2,4,6,8,10)" << bytes.toString();
//    bytes.rollBackward(3);
//    qDebug() << "bytes.rollBackward(3)" << bytes.toString();
//    bytes.swap(1, 3);
//    qDebug() << "bytes.swap(1, 3)" << bytes.toString();
//    bytes.sort(false);
//    qDebug() << "bytes.sort(false)" << bytes.toString();
//    bytes.sort(true);
//    qDebug() << "bytes.sort(true)" << bytes.toString();   
    
//    Bytes b1("(1,2,3)");
//    Bytes b2 = b1;
//    qDebug() << "b1" << b1.toString() << "b2" << b2.toString();    
//    qDebug() << "(b2 == b1)" << (b2 == b1);
//    qDebug() << "(b2 != b1)" << (b2 != b1);
//    b1.clear();
//    qDebug() << "b1.clear(), b1" << b1.toString() << "b2" << b2.toString();    
//    qDebug() << "(b2 == b1)" << (b2 == b1);
//    qDebug() << "(b2 != b1)" << (b2 != b1); 
//}

QString Bytes::toString()
{
    QStringList sb;
    foreach(uchar ch, data)
        sb << QString::number((uint)ch);
    QString result = QString("(") + sb.join(",") + QString(")");
    return result;    
}

int Bytes::fromString(const QString &input)
{
    int len = input.length();
    if (!input.startsWith('(') || !input.endsWith(')')) return 0;
    int n = 1;
    QString s, sb;
    QList<uchar> newData;
    bool ok;
    while (n < len)
    {
        s = input.mid(n, 1);
        if (s != "," && s != ")")
            sb += s;
        else
        {
            newData << (uchar)(sb.toUInt(&ok));
            if (!ok)
                return 0;
            sb.clear();
        }
        n++;
    }
    data = newData;
    return 1;   
}

void Bytes::sort(bool decending)
{
    qSort(data.begin(), data.end(), decending ? descSorter<uchar> : ascSorter<uchar>);
}

QString Text::to_hex(const QString &input)
{
    QString output = input.toUtf8().toHex();
    return output;
}

QString Text::from_hex(const QString &input)
{
    QString output;
    int len = input.length();
	if ((len % 2) == 0)
    {
        QByteArray a;
        bool ok = false;
        for (int n = 0; n < len; n += 2)
        {
            ok = true;
            a.append((char)input.mid(n, 2).toInt(&ok, 16));
            if (!ok)
                break;
        }
        if (ok && !a.isEmpty())
            output = QString::fromUtf8(a);
    }
    return output;
}

QString Text::to_md5(const QString &input)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
	hash.addData(input.toUtf8());
	QString output = hash.result();    
    return output;
}

QString Text::to_base64(const QString &input)
{
    QString output = input.toUtf8().toBase64();
    return output;
}

QString Text::from_base64(const QString &input)
{
    QString output = QByteArray::fromBase64(input.toUtf8());
    return output;
}

static HashCodeType globalUid = 0;

template<typename T>
HashCodeType Node<T>::nextUid()
{
    return ++globalUid;    
}

template<typename T>
HashCodeType Node<T>::uid()
{
    return mUid;
}

template<typename T>
bool Node<T>::hit(Node<T> *item)
{
    if (!item) return false;
    return item->uid() == this->uid();
}

template<typename T>
Node<T>* Node<T>::next()
{
    if (!Parent) return 0;
    int len = Parent->Children.length();
    for (int n = 0; n < len; n++)
    {
        if (hit(Parent->Children.get(n)))
            return (n == len-1) ? 0 : Parent->Children.get(n+1);
    }
    return 0;
}

template<typename T>
Node<T>* Node<T>::previous()
{
    if (!Parent) return 0;
    int len = Parent->Children.length();
    for (int n = 0; n < len; n++)
    {
        if (hit(Parent->Children.get(n)))
            return (n == 0) ? 0 : Parent->Children.get(n-1);
    }
    return 0;    
}

template<typename T>
int Node<T>::indexOfChild(Node<T> *item)
{
    int len = Children.length();
    for (int n = 0; n < len; n++)
    {
        if (Node<T>* child = Children.get(n))
        {
            if (child->hit(item))
                return n;
        }
    }
    return -1;    
}

template<typename T>
bool Node<T>::removeChild(int index)
{
    return Children.remove(index);
}

template<typename T>
bool Node<T>::removeChild(Node<T> *item)
{
    int index = indexOfChild(item);
    return (index > -1) ? removeChild(index) : false;
}

template<typename T>
Node<T>* Node<T>::appendChild(Node<T> *item)
{
    Children.append(item);
    if (item)
        item->Parent = this;
    return item;
}

template<typename T>
Node<T>* Node<T>::insertChild(int index, Node<T> *newItem)
{
    return Children.insert(index, newItem) ? newItem : 0;
}

template<typename T>
Node<T> *Node<T>::insertChild(Node<T> *item, Node<T> *newItem)
{
    int index = indexOfChild(item);
    if (index == -1)
        return 0;
    return Children.insert(index, newItem) ? newItem : 0;
}

template<typename T>
Node<T>::Node(T value)
{
    mUid = nextUid();
    Value = value;
    Parent = 0;
}

template<typename T>
Node<T>::~Node()
{
    int len = Children.length();
    for (int n = 0; n < len; n++)
    {
        if (Node<T>* child = Children.get(n))
            delete child;
    }
}

template<typename T>
Node<T>* Node<T>::create(T value)
{
    return new Node<T>(value);
}

}

void nodeInt32Test()
{
    onelab::Node<int>* root = onelab::Node<int>::create(20170527);
    onelab::Node<int>* n0 = root->appendChild(onelab::Node<int>::create(101));
    onelab::Node<int>* n1 = root->appendChild(onelab::Node<int>::create(102));
    onelab::Node<int>* n2 = root->appendChild(onelab::Node<int>::create(103));
    
    bool testIndex = root->indexOfChild(n0) == 0;
    bool testIndex2 = root->indexOfChild(n1) == 1;
    bool testIndex3 = root->indexOfChild(n2) == 2;
    
    bool testPrevious = n1->previous()->hit(n0);
    bool testPrevious2 = n1->previous()->hit(n2);
    bool testNext = n1->next()->hit(n2);
    bool testNext2 = n1->next()->hit(n1);
    
    root->removeChild(n0);
    bool testLen = root->Children.length() == 2;
    root->removeChild(n1);
    bool testLen2 = root->Children.length() == 1;
    root->removeChild(n2);
    bool testLen3 = root->Children.length() == 0;
    
    return;    
}
