#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <stdio.h>
#include <time.h>
#include <QDateTime>

class Qt_dt_testTest : public QObject
{
	Q_OBJECT
	
public:
	Qt_dt_testTest();
	
private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();
	void testCase1();
	void testCase1_data();
};

Qt_dt_testTest::Qt_dt_testTest()
{
	printf("[%s,%d] \n" , __func__, __LINE__);
}

void Qt_dt_testTest::initTestCase()
{
	printf("================================> [%s,%d] \n\n\n\n" , __func__, __LINE__);

	QDateTime dt_current ;
	dt_current = QDateTime::currentDateTime();

	time_t _mSecSinceEpoch = (time_t)dt_current.toMSecsSinceEpoch();
	time_t _time_t = (time_t)dt_current.toTime_t();

	time_t _utc_mSecSinceEpoch = (time_t)dt_current.toUTC().toMSecsSinceEpoch();
	time_t _utc_time_t = (time_t)dt_current.toUTC().toTime_t();

	printf( "[_mSecSinceEpoch] (%d)(%s)  \n", _mSecSinceEpoch , ctime( &_mSecSinceEpoch ));
	printf( "[_time_t]         (%d)(%s)  \n", _time_t ,ctime( &_time_t ));

	printf( "[_utc_mSecSinceEpoch] (%d)(%s)  \n", _utc_mSecSinceEpoch , ctime( &_utc_mSecSinceEpoch ));
	printf( "[_utc_time_t]         (%d)(%s)  \n", _utc_time_t , ctime( &_utc_time_t ));

}

void Qt_dt_testTest::cleanupTestCase()
{
	printf("================================> [%s,%d] \n\n\n\n" , __func__, __LINE__);
	QDateTime dt_current ;
	dt_current = QDateTime::currentDateTimeUtc() ;

	time_t _mSecSinceEpoch = (time_t)dt_current.toMSecsSinceEpoch();
	time_t _time_t = (time_t)dt_current.toTime_t();

	time_t _utc_mSecSinceEpoch = (time_t)dt_current.toUTC().toMSecsSinceEpoch();
	time_t _utc_time_t = (time_t)dt_current.toUTC().toTime_t();

	printf( "[_mSecSinceEpoch] (%d)(%s)  \n", _mSecSinceEpoch , ctime( &_mSecSinceEpoch ));
	printf( "[_time_t]         (%d)(%s)  \n", _time_t ,ctime( &_time_t ));

	printf( "[_utc_mSecSinceEpoch] (%d)(%s)  \n", _utc_mSecSinceEpoch , ctime( &_utc_mSecSinceEpoch ));
	printf( "[_utc_time_t]         (%d)(%s)  \n", _utc_time_t , ctime( &_utc_time_t ));

}

void Qt_dt_testTest::testCase1()
{
	printf("[%s,%d] \n" , __func__, __LINE__);
	QFETCH(QString, data);
	QVERIFY2(true, "Failure");

}

void Qt_dt_testTest::testCase1_data()
{
	printf("[%s,%d] \n" , __func__, __LINE__);
	QTest::addColumn<QString>("data");
	QTest::newRow("0") << QString();
}

QTEST_MAIN(Qt_dt_testTest)

#include "tst_qt_dt_testtest.moc"

