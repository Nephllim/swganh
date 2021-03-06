/*
 This file is part of MMOServer. For more information, visit http://swganh.com
 
 Copyright (c) 2006 - 2010 The SWG:ANH Team

 MMOServer is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 MMOServer is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with MMOServer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ANH_DATABASE_MOCK_CPPCONN_H_
#define ANH_DATABASE_MOCK_CPPCONN_H_

#include <gmock/gmock.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/metadata.h>
#include <cppconn/parameter_metadata.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/statement.h>

// Generate mock objects for the Mysql Connector/C++ interface.

namespace anh {
namespace database {

class MockDriver : public sql::Driver {
public:
    MOCK_METHOD3(connect, sql::Connection*(const sql::SQLString& hostName, const sql::SQLString& userName, const sql::SQLString& password));
    MOCK_METHOD1(connect, sql::Connection*(sql::ConnectOptionsMap& options));
    MOCK_METHOD0(getMajorVersion, int());
    MOCK_METHOD0(getMinorVersion, int());
    MOCK_METHOD0(getPatchVersion, int());
    MOCK_METHOD0(getName, const sql::SQLString&());
    MOCK_METHOD0(threadInit, void());
    MOCK_METHOD0(threadEnd, void());
};

class MockConnection : public sql::Connection {
public:
    MOCK_METHOD0(clearWarnings, void());
    MOCK_METHOD0(createStatement, sql::Statement*());
    MOCK_METHOD0(close, void());
    MOCK_METHOD0(commit, void());
    MOCK_METHOD0(getAutoCommit, bool());
    MOCK_METHOD0(getCatalog, sql::SQLString());
    MOCK_METHOD0(getDriver, sql::Driver*());
    MOCK_METHOD0(getSchema, sql::SQLString());
    MOCK_METHOD0(getClientInfo, sql::SQLString());
    MOCK_METHOD2(getClientOption, void(const sql::SQLString& optionName, void* optionValue));
    MOCK_METHOD0(getMetaData, sql::DatabaseMetaData*());
    MOCK_METHOD0(getTransactionIsolation, sql::enum_transaction_isolation());
    MOCK_METHOD0(getWarnings, const sql::SQLWarning*());
    MOCK_METHOD0(isClosed, bool());
    MOCK_METHOD0(isReadOnly, bool());
    MOCK_METHOD1(nativeSQL, sql::SQLString(const sql::SQLString& sql));
    MOCK_METHOD1(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql));
    MOCK_METHOD2(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql, int autoGeneratedKeys));
    MOCK_METHOD2(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql, int* columnIndexes));
    MOCK_METHOD3(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql, int resultSetType, int resultSetConcurrency));
    MOCK_METHOD4(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql, int resultSetType, int resultSetConcurrency, int resultSetHoldability));
    MOCK_METHOD2(prepareStatement, sql::PreparedStatement*(const sql::SQLString& sql, sql::SQLString columnNames[]));
    MOCK_METHOD1(releaseSavepoint, void(sql::Savepoint* savepoint));
    MOCK_METHOD0(rollback, void());
    MOCK_METHOD1(rollback, void(sql::Savepoint* savepoint));
    MOCK_METHOD1(setAutoCommit, void(bool autoCommit));
    MOCK_METHOD1(setCatalog, void(const sql::SQLString& catalog));
    MOCK_METHOD1(setSchema, void(const sql::SQLString& catalog));
    MOCK_METHOD2(setClientOption, sql::Connection*(const sql::SQLString& optionName, const void* optionValue));
    MOCK_METHOD1(setHoldability, void(int holdability));
    MOCK_METHOD1(setReadOnly, void(bool readOnly));
    MOCK_METHOD0(setSavepoint, sql::Savepoint*());
    MOCK_METHOD1(setSavepoint, sql::Savepoint*(const sql::SQLString& name));
    MOCK_METHOD1(setTransactionIsolation, void(sql::enum_transaction_isolation level));
};

class MockStatement : public sql::Statement {
public:
    MOCK_METHOD0(getConnection, sql::Connection*());
    MOCK_METHOD0(cancel, void());
    MOCK_METHOD0(clearWarnings, void());
    MOCK_METHOD0(close, void());
    MOCK_METHOD1(execute, bool(const sql::SQLString& sql));
    MOCK_METHOD1(executeQuery, sql::ResultSet*(const sql::SQLString& sql));
    MOCK_METHOD1(executeUpdate, int(const sql::SQLString& sql));
    MOCK_METHOD0(getFetchSize, size_t());
    MOCK_METHOD0(getMaxFieldSize, unsigned int());
    MOCK_METHOD0(getMaxRows, uint64_t());
    MOCK_METHOD0(getMoreResults, bool());
    MOCK_METHOD0(getQueryTimeout, unsigned int());
    MOCK_METHOD0(getResultSet, sql::ResultSet*());
    MOCK_METHOD0(getResultSetType, sql::ResultSet::enum_type());
    MOCK_METHOD0(getUpdateCount, uint64_t());
    MOCK_METHOD0(getWarnings, const sql::SQLWarning*());
    MOCK_METHOD1(setCursorName, void(const sql::SQLString& name));
    MOCK_METHOD1(setEscapeProcessing, void(bool enable));
    MOCK_METHOD1(setFetchSize, void(size_t rows));
    MOCK_METHOD1(setMaxFieldSize, void(unsigned int max));
    MOCK_METHOD1(setMaxRows, void(unsigned int max));
    MOCK_METHOD1(setQueryTimeout, void(unsigned int seconds));
    MOCK_METHOD1(setResultSetType, sql::Statement*(sql::ResultSet::enum_type type));
};

class MockPreparedStatement : public sql::Statement {
public:
    MOCK_METHOD0(clearParameters, void());
    MOCK_METHOD1(execute, bool(const sql::SQLString& sql));
    MOCK_METHOD0(execute, bool());
    MOCK_METHOD1(executeQuery, sql::ResultSet*(const sql::SQLString& sql));
    MOCK_METHOD0(executeQuery, sql::ResultSet*());
    MOCK_METHOD1(executeUpdate, int(const sql::SQLString& sql));
    MOCK_METHOD0(executeUpdate, int());
    MOCK_METHOD0(getMetaData, sql::ResultSetMetaData*());
    MOCK_METHOD0(getParameterMetaData, sql::ParameterMetaData*());
    MOCK_METHOD2(setBigInt, void(unsigned int parameterIndex, const sql::SQLString& value));
    MOCK_METHOD2(setBlob, void(unsigned int parameterIndex, std::istream* blob));
    MOCK_METHOD2(setBoolean, void(unsigned int parameterIndex, bool value));
    MOCK_METHOD2(setDateTime, void(unsigned int parameterIndex, const sql::SQLString& value));
    MOCK_METHOD2(setDouble, void(unsigned int parameterIndex, double value));
    MOCK_METHOD2(setInt, void(unsigned int parameterIndex, int32_t value));
    MOCK_METHOD2(setUInt, void(unsigned int parameterIndex, uint32_t value));
    MOCK_METHOD2(setInt64, void(unsigned int parameterIndex, int64_t value));
    MOCK_METHOD2(setUInt64, void(unsigned int parameterIndex, uint64_t value));
    MOCK_METHOD2(setNull, void(unsigned int parameterIndex, int sqlType));
    MOCK_METHOD2(setString, void(unsigned int parameterIndex, const sql::SQLString& value));
    MOCK_METHOD1(setResultSetType, sql::PreparedStatement*(sql::ResultSet::enum_type type));
};

class MockResultSet : public sql::ResultSet {
public:
    MOCK_METHOD1(absolute, bool(int row));
    MOCK_METHOD0(afterLast, void());
    MOCK_METHOD0(beforeFirst, void());
    MOCK_METHOD0(cancelRowUpdates, void());
    MOCK_METHOD0(clearWarnings, void());
    MOCK_METHOD0(close, void());
    MOCK_CONST_METHOD1(findColumn, uint32_t(const sql::SQLString& columnLabel));
    MOCK_METHOD0(first, bool());
    MOCK_CONST_METHOD1(getBlob, std::istream*(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getBlob, std::istream*(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD1(getBoolean, bool(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getBoolean, bool(const sql::SQLString& columnLabel));
    MOCK_METHOD0(getConcurrency, int());
    MOCK_METHOD0(getCursorName, sql::SQLString());
    MOCK_CONST_METHOD1(getDouble, long double(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getDouble, long double(const sql::SQLString& columnLabel));
    MOCK_METHOD0(getFetchDirection, int());
    MOCK_METHOD0(getFetchSize, size_t());
    MOCK_METHOD0(getHoldability, int());
    MOCK_CONST_METHOD1(getInt, int32_t(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getInt, int32_t(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD1(getUInt, uint32_t(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getUInt, uint32_t(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD1(getInt64, int64_t(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getInt64, int64_t(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD1(getUInt64, uint64_t(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getUInt64, uint64_t(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD0(getMetaData, sql::ResultSetMetaData*());
    MOCK_CONST_METHOD0(getRow, size_t());
    MOCK_METHOD1(getRowId, sql::RowID*(uint32_t columnIndex));
    MOCK_METHOD1(getRowId, sql::RowID*(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD0(getStatement, const sql::Statement*());
    MOCK_CONST_METHOD1(getString, sql::SQLString(uint32_t columnIndex));
    MOCK_CONST_METHOD1(getString, sql::SQLString(const sql::SQLString& columnLabel));
    MOCK_CONST_METHOD0(getType, sql::ResultSet::enum_type());
    MOCK_METHOD0(getWarnings, void());
    MOCK_METHOD0(insertRow, void());
    MOCK_CONST_METHOD0(isAfterLast, bool());
    MOCK_CONST_METHOD0(isBeforeFirst, bool());
    MOCK_CONST_METHOD0(isClosed, bool());
    MOCK_CONST_METHOD0(isFirst, bool());
    MOCK_CONST_METHOD0(isLast, bool());
    MOCK_CONST_METHOD1(isNull, bool(uint32_t columnIndex));
    MOCK_CONST_METHOD1(isNull, bool(const sql::SQLString& columnLabel));
    MOCK_METHOD0(last, bool());
    MOCK_METHOD0(next, bool());
    MOCK_METHOD0(moveToCurrentRow, void());
    MOCK_METHOD0(moveToInsertRow, void());
    MOCK_METHOD0(previous, bool());
    MOCK_METHOD0(refreshRow, void());
    MOCK_METHOD1(relative, bool(int rows));
    MOCK_METHOD0(rowDeleted, bool());
    MOCK_METHOD0(rowInserted, bool());
    MOCK_METHOD0(rowUpdated, bool());
    MOCK_METHOD1(setFetchSize, void(size_t rows));
    MOCK_CONST_METHOD0(rowsCount, size_t());
    MOCK_CONST_METHOD0(wasNull, bool());
};

}  // namespace database
}  // namespace anh

#endif  // ANH_DATABASE_MOCK_CPPCONN_H_
