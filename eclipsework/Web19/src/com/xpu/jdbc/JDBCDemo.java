	package com.xpu.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCDemo {

	public static void main(String[] args) {
		Connection conn = null;
		// 通过JDBC控制事物
		try {
			// [1]注册驱动
			Class.forName("com.mysql.jdbc.Driver");

			// [2]获得Connection
			conn = DriverManager.getConnection("jdbc:mysql:///web_19", "root", "1234");

			// 手动开启事务
			conn.setAutoCommit(false);// 设置非自动提交

			// [3]获取执行平台
			Statement stmt = conn.createStatement();

			// [4]操作MySQL
			stmt.executeUpdate("insert into account values(null,'jack-0',300)");
			
			stmt.executeUpdate("insert into account values(null,'jack+1',3501)");
			int ret = stmt.executeUpdate("update account set money=5000 where name='tom'");
			if(ret == 1){
				//TODO 这才是成功，SQL像name找不到这种事情是不会抛出异常的
			}
			
			//手动提交事务
			conn.commit();
			
			// [5]关闭资源
			stmt.close();
			conn.close();
			
			
		} catch (Exception e) {
			try {
				conn.rollback();
			} catch (SQLException e1) {
				e1.printStackTrace();
			}
			e.printStackTrace();
		} 
	}
}
