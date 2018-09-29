package com.xpu.transaction.service;

import java.sql.SQLException;

import com.xpu.transaction.dao.TransferDao;

public class TransferService {

	public boolean transfer(String out, String in, double money) {
		boolean isSuccess = true;
		//创建Dao层对象
		TransferDao dao = new TransferDao();
		
		//转出钱的方法
		try {
			dao.out(out,money);
			dao.in(in,money);
		} catch (SQLException e) {
			isSuccess = false;
			e.printStackTrace();
		}
		return isSuccess;
	}
}
