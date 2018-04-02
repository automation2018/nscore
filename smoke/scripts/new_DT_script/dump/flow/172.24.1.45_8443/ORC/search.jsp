<!DOCTYPE html><html><head><title>Apache Tomcat/8.5.11 - Error report</title><style type="text/css">h1 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:22px;} h2 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:16px;} h3 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:14px;} body {font-family:Tahoma,Arial,sans-serif;color:black;background-color:white;} b {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;} p {font-family:Tahoma,Arial,sans-serif;background:white;color:black;font-size:12px;} a {color:black;} a.name {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style> </head><body><h1>HTTP Status 500 - An exception occurred processing JSP page /makecon.jsp at line 11</h1><div class="line"></div><p><b>type</b> Exception report</p><p><b>message</b> <u>An exception occurred processing JSP page /makecon.jsp at line 11</u></p><p><b>description</b> <u>The server encountered an internal error that prevented it from fulfilling this request.</u></p><p><b>exception</b></p><pre>org.apache.jasper.JasperException: An exception occurred processing JSP page /makecon.jsp at line 11

8: 		Class.forName(&quot;com.mysql.jdbc.Driver&quot;).newInstance(); 
9: 
10:         con = //DriverManager.getConnection(&quot;jdbc:oracle:thin:@192.168.0.2:1521:tit&quot;,&quot;scott&quot;,&quot;tiger&quot;);
11: 		DriverManager.getConnection(&quot;jdbc:mysql://localhost/project_db&quot;,&quot;my_user&quot;,&quot;manisha@7&quot;);
12: 	st=con.createStatement();
13: %&gt;


Stacktrace:
	org.apache.jasper.servlet.JspServletWrapper.handleJspException(JspServletWrapper.java:584)
	org.apache.jasper.servlet.JspServletWrapper.service(JspServletWrapper.java:466)
	org.apache.jasper.servlet.JspServlet.serviceJspFile(JspServlet.java:385)
	org.apache.jasper.servlet.JspServlet.service(JspServlet.java:329)
	javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:52)
</pre><p><b>root cause</b></p><pre>javax.servlet.ServletException: com.mysql.jdbc.CommunicationsException: Communications link failure due to underlying exception: 

** BEGIN NESTED EXCEPTION ** 

java.net.SocketException
MESSAGE: java.net.ConnectException: Connection refused (Connection refused)

STACKTRACE:

java.net.SocketException: java.net.ConnectException: Connection refused (Connection refused)
	at com.mysql.jdbc.StandardSocketFactory.connect(StandardSocketFactory.java:156)
	at com.mysql.jdbc.MysqlIO.&lt;init&gt;(MysqlIO.java:284)
	at com.mysql.jdbc.Connection.createNewIO(Connection.java:2569)
	at com.mysql.jdbc.Connection.&lt;init&gt;(Connection.java:1485)
	at com.mysql.jdbc.NonRegisteringDriver.connect(NonRegisteringDriver.java:266)
	at java.sql.DriverManager.getConnection(DriverManager.java:664)
	at java.sql.DriverManager.getConnection(DriverManager.java:247)
	at org.apache.jsp.search_jsp._jspService(search_jsp.java:142)
	at org.apache.jasper.runtime.HttpJspBase.service(HttpJspBase.java:70)
	at javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	at org.apache.jasper.servlet.JspServletWrapper.service(JspServletWrapper.java:443)
	at org.apache.jasper.servlet.JspServlet.serviceJspFile(JspServlet.java:385)
	at org.apache.jasper.servlet.JspServlet.service(JspServlet.java:329)
	at javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:230)
	at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:165)
	at org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:52)
	at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:192)
	at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:165)
	at org.apache.catalina.core.StandardWrapperValve.invoke(StandardWrapperValve.java:198)
	at org.apache.catalina.core.StandardContextValve.invoke(StandardContextValve.java:96)
	at org.apache.catalina.authenticator.AuthenticatorBase.invoke(AuthenticatorBase.java:591)
	at org.apache.catalina.core.StandardHostValve.invoke(StandardHostValve.java:140)
	at org.apache.catalina.valves.ErrorReportValve.invoke(ErrorReportValve.java:79)
	at org.apache.catalina.valves.AbstractAccessLogValve.invoke(AbstractAccessLogValve.java:624)
	at org.apache.catalina.core.StandardEngineValve.invoke(StandardEngineValve.java:87)
	at org.apache.catalina.connector.CoyoteAdapter.service(CoyoteAdapter.java:349)
	at org.apache.coyote.http11.Http11Processor.service(Http11Processor.java:783)
	at org.apache.coyote.AbstractProcessorLight.process(AbstractProcessorLight.java:66)
	at org.apache.coyote.AbstractProtocol$ConnectionHandler.process(AbstractProtocol.java:798)
	at org.apache.tomcat.util.net.NioEndpoint$SocketProcessor.doRun(NioEndpoint.java:1434)
	at org.apache.tomcat.util.net.SocketProcessorBase.run(SocketProcessorBase.java:49)
	at java.util.concurrent.ThreadPoolExecutor.runWorker(ThreadPoolExecutor.java:1149)
	at java.util.concurrent.ThreadPoolExecutor$Worker.run(ThreadPoolExecutor.java:624)
	at org.apache.tomcat.util.threads.TaskThread$WrappingRunnable.run(TaskThread.java:61)
	at java.lang.Thread.run(Thread.java:748)


** END NESTED EXCEPTION **



Last packet sent to the server was 0 ms ago.
	org.apache.jasper.runtime.PageContextImpl.doHandlePageException(PageContextImpl.java:909)
	org.apache.jasper.runtime.PageContextImpl.handlePageException(PageContextImpl.java:838)
	org.apache.jsp.search_jsp._jspService(search_jsp.java:290)
	org.apache.jasper.runtime.HttpJspBase.service(HttpJspBase.java:70)
	javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	org.apache.jasper.servlet.JspServletWrapper.service(JspServletWrapper.java:443)
	org.apache.jasper.servlet.JspServlet.serviceJspFile(JspServlet.java:385)
	org.apache.jasper.servlet.JspServlet.service(JspServlet.java:329)
	javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:52)
</pre><p><b>root cause</b></p><pre>com.mysql.jdbc.CommunicationsException: Communications link failure due to underlying exception: 

** BEGIN NESTED EXCEPTION ** 

java.net.SocketException
MESSAGE: java.net.ConnectException: Connection refused (Connection refused)

STACKTRACE:

java.net.SocketException: java.net.ConnectException: Connection refused (Connection refused)
	at com.mysql.jdbc.StandardSocketFactory.connect(StandardSocketFactory.java:156)
	at com.mysql.jdbc.MysqlIO.&lt;init&gt;(MysqlIO.java:284)
	at com.mysql.jdbc.Connection.createNewIO(Connection.java:2569)
	at com.mysql.jdbc.Connection.&lt;init&gt;(Connection.java:1485)
	at com.mysql.jdbc.NonRegisteringDriver.connect(NonRegisteringDriver.java:266)
	at java.sql.DriverManager.getConnection(DriverManager.java:664)
	at java.sql.DriverManager.getConnection(DriverManager.java:247)
	at org.apache.jsp.search_jsp._jspService(search_jsp.java:142)
	at org.apache.jasper.runtime.HttpJspBase.service(HttpJspBase.java:70)
	at javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	at org.apache.jasper.servlet.JspServletWrapper.service(JspServletWrapper.java:443)
	at org.apache.jasper.servlet.JspServlet.serviceJspFile(JspServlet.java:385)
	at org.apache.jasper.servlet.JspServlet.service(JspServlet.java:329)
	at javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:230)
	at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:165)
	at org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:52)
	at org.apache.catalina.core.ApplicationFilterChain.internalDoFilter(ApplicationFilterChain.java:192)
	at org.apache.catalina.core.ApplicationFilterChain.doFilter(ApplicationFilterChain.java:165)
	at org.apache.catalina.core.StandardWrapperValve.invoke(StandardWrapperValve.java:198)
	at org.apache.catalina.core.StandardContextValve.invoke(StandardContextValve.java:96)
	at org.apache.catalina.authenticator.AuthenticatorBase.invoke(AuthenticatorBase.java:591)
	at org.apache.catalina.core.StandardHostValve.invoke(StandardHostValve.java:140)
	at org.apache.catalina.valves.ErrorReportValve.invoke(ErrorReportValve.java:79)
	at org.apache.catalina.valves.AbstractAccessLogValve.invoke(AbstractAccessLogValve.java:624)
	at org.apache.catalina.core.StandardEngineValve.invoke(StandardEngineValve.java:87)
	at org.apache.catalina.connector.CoyoteAdapter.service(CoyoteAdapter.java:349)
	at org.apache.coyote.http11.Http11Processor.service(Http11Processor.java:783)
	at org.apache.coyote.AbstractProcessorLight.process(AbstractProcessorLight.java:66)
	at org.apache.coyote.AbstractProtocol$ConnectionHandler.process(AbstractProtocol.java:798)
	at org.apache.tomcat.util.net.NioEndpoint$SocketProcessor.doRun(NioEndpoint.java:1434)
	at org.apache.tomcat.util.net.SocketProcessorBase.run(SocketProcessorBase.java:49)
	at java.util.concurrent.ThreadPoolExecutor.runWorker(ThreadPoolExecutor.java:1149)
	at java.util.concurrent.ThreadPoolExecutor$Worker.run(ThreadPoolExecutor.java:624)
	at org.apache.tomcat.util.threads.TaskThread$WrappingRunnable.run(TaskThread.java:61)
	at java.lang.Thread.run(Thread.java:748)


** END NESTED EXCEPTION **



Last packet sent to the server was 0 ms ago.
	com.mysql.jdbc.Connection.createNewIO(Connection.java:2643)
	com.mysql.jdbc.Connection.&lt;init&gt;(Connection.java:1485)
	com.mysql.jdbc.NonRegisteringDriver.connect(NonRegisteringDriver.java:266)
	java.sql.DriverManager.getConnection(DriverManager.java:664)
	java.sql.DriverManager.getConnection(DriverManager.java:247)
	org.apache.jsp.search_jsp._jspService(search_jsp.java:142)
	org.apache.jasper.runtime.HttpJspBase.service(HttpJspBase.java:70)
	javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	org.apache.jasper.servlet.JspServletWrapper.service(JspServletWrapper.java:443)
	org.apache.jasper.servlet.JspServlet.serviceJspFile(JspServlet.java:385)
	org.apache.jasper.servlet.JspServlet.service(JspServlet.java:329)
	javax.servlet.http.HttpServlet.service(HttpServlet.java:729)
	org.apache.tomcat.websocket.server.WsFilter.doFilter(WsFilter.java:52)
</pre><p><b>note</b> <u>The full stack trace of the root cause is available in the Apache Tomcat/8.5.11 logs.</u></p><hr class="line"><h3>Apache Tomcat/8.5.11</h3></body></html>
