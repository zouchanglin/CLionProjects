package com.xpu.bean;

public class Member {
	private String name;
	private String email;
	private String phone;
	private String proClass;
	private String subject;
	private String message;
	
	public Member() {
		super();
	}

	public Member(String name, String email, String phone, String proClass, String subject, String message) {
		super();
		this.name = name;
		this.email = email;
		this.phone = phone;
		this.proClass = proClass;
		this.subject = subject;
		this.message = message;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getProClass() {
		return proClass;
	}

	public void setProClass(String proClass) {
		this.proClass = proClass;
	}

	public String getSubject() {
		return subject;
	}

	public void setSubject(String subject) {
		this.subject = subject;
	}

	@Override
	public String toString() {
		return name + "," + email + "," + phone + "," + proClass
				+ "," + subject + ", " + message;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}
	
	
}
