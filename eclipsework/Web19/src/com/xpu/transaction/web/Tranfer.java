package com.xpu.transaction.web;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.xpu.transaction.service.TransferService;

/**
 * Servlet implementation class Tranfer
 */
public class Tranfer extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Tranfer() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//接受参数
		String out = request.getParameter("out");
		String in = request.getParameter("in");
		double money = Double.valueOf(request.getParameter("money"));
		
		//调用业务层方法
		TransferService service = new TransferService();
		boolean istransfer = service.transfer(out,in,money);
		
		response.setContentType("text/html;charset=UTF-8");
		if(istransfer){
			response.getWriter().write("转账成功");
		}else{
			response.getWriter().write("转账失败");
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
