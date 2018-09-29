package com.xpu.servlet;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.xpu.bean.Member;

import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;

/**
 * Servlet implementation class Regservlet
 */
public class Regservlet extends HttpServlet {

	private static ArrayList<Member> mem_arr = new ArrayList<>();
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public Regservlet() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		// 写入表格
		//OutputStream os = new FileOutputStream("C:\\Users\\Tim\\Desktop\\info.xls");
		//TODO Linux路径
		OutputStream os = new FileOutputStream("/root/info.xls");
		// 创建workbook
		WritableWorkbook wwb = Workbook.createWorkbook(os);

		// 获取表单信息
		com.xpu.bean.Member member = new com.xpu.bean.Member(
				new String(request.getParameter("Name").getBytes("ISO8859-1"),"UTF-8"),
				new String(request.getParameter("Email").getBytes("ISO8859-1"),"UTF-8"),
				new String(request.getParameter("Phone").getBytes("ISO8859-1"),"UTF-8"),
				new String(request.getParameter("ProClass").getBytes("ISO8859-1"),"UTF-8"),
				new String(request.getParameter("Subject").getBytes("ISO8859-1"),"UTF-8"),
				new String(request.getParameter("Message").getBytes("ISO8859-1"),"UTF-8")
				);
		mem_arr.add(member);
		System.out.println(member);
		// 写入文件
		//BufferedWriter bw = new BufferedWriter(new FileWriter(new File("C:\\Users\\Tim\\Desktop\\info.txt"), true));
		//TODO Linux路径
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("/root/info.txt"), true));
		bw.write(member.toString());
		bw.newLine();
		bw.close();

		// 创建Excel工作表指定名称和位置
		WritableSheet ws = wwb.createSheet("sheet", 0);
		// 写入
		try {
			for (int index = 0; index < mem_arr.size(); index++) {
				Member mem = mem_arr.get(index);
				System.out.println(mem);
				ws.addCell(new Label(0,index,mem.getName()));
				ws.addCell(new Label(1,index,mem.getEmail()));
				ws.addCell(new Label(2,index,mem.getPhone()));
				ws.addCell(new Label(3,index,mem.getProClass()));
				ws.addCell(new Label(4,index,mem.getSubject()));
				ws.addCell(new Label(5,index,mem.getMessage()));
			}
			wwb.write();
			wwb.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		// 关闭资源
		os.close();
		response.sendRedirect("successful_register.html");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
