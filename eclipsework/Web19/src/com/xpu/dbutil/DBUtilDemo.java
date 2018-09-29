package com.xpu.dbutil;

import java.sql.Connection;
import java.sql.SQLException;

import org.apache.commons.dbutils.QueryRunner;

import com.xpu.util.DataSourceUtils;

public class DBUtilDemo {

	public static void main(String[] args) {
		Connection conn = null;
		try {
			QueryRunner runner = new QueryRunner();			
			conn = DataSourceUtils.getConnection();
			
			//开启事务
			conn.setAutoCommit(false);
			runner.update(conn, "update account set money=10000 where name='tom'");
			
			//提交或者回滚事务
			conn.commit();
			
		} catch (SQLException e) {
			try {
				conn.rollback();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
	}
}
