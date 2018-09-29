package com.xpu.transaction.dao;

import java.sql.Connection;
import java.sql.SQLException;

import org.apache.commons.dbutils.QueryRunner;

import com.xpu.util.DataSourceUtils;

public class TransferDao {

	public void out(String out, double money) throws SQLException {
		QueryRunner runner = new QueryRunner();
		Connection conn = DataSourceUtils.getConnection();
		String sql = "UPDATE account set money=money-? where name=?";
		runner.update(conn,sql,money,out);
	}

	public void in(String in, double money) throws SQLException {
		QueryRunner runner = new QueryRunner();
		Connection conn = DataSourceUtils.getConnection();
		String sql = "UPDATE account set money=money+? where name=?";
		runner.update(conn,sql,money,in);
	}

}
