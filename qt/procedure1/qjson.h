#ifndef _QJSON_H_
#define _QJSON_H_
#include "QtCore/qmap.h"
#include "QtCore/qlist.h"
#include "QtCore/qvariant.h"
#include "QtCore/qregexp.h"
#include "QtCore/qstringlist.h"

class QJson {

public:
	QJson();
	virtual ~QJson();
	QVariant decode(const QString& jsonString);
	QString encode(const QVariant& jsonObject);

private:
	enum Error {
		ErrorUnrecognizedToken,
		ErrorMustBeString,
		ErrorMissingColon,
		ErrorMissingCommaOrClose,
		ErrorNoClosingQuote,
		ErrorEndOfInput,
		ErrorInvalidNumericValue,
		ErrorInvalidHexValue,
		ErrorUnrecognizedObject
	};

	QRegExp mNonBlank;
	QRegExp mFindQuote;

	QString nextToken(const QString& jsonString, int& position);
	QString peekToken(const QString& jsonString, int position);
	QVariant parseInternal(const QString& jsonString, int& position, int nesting);
	QVariant parseObject(const QString& jsonString, int& position, int nesting);
	QVariant parseArray(const QString& jsonString, int& position, int nesting);
	QVariant parseString(const QString& jsonString, int& position, int nesting);
	QVariant parseBool(const QString& jsonString, int& position, int nesting);
	QVariant parseNull(const QString& jsonString, int& position, int nesting);
	QVariant parseNumber(const QString& jsonString, int& position, int nesting);
	QVariant syntaxError(const QString& method, const QString& jsonString, int position, int nesting, Error error);

	QString encodeObject(const QVariant& jsonObject);
	QString encodeArray(const QVariant& jsonObject);
	QString encodeString(const QVariant& jsonObject);
	QString encodeString(const QString& value);
	QString encodeNumeric(const QVariant& jsonObject);
	QString encodeBool(const QVariant& jsonObject);
	QString encodeNull(const QVariant& jsonObject);
	QString encodingError(const QString& method, const QVariant& jsonObject, Error error);
};

#endif /* _QJSON_H_ */