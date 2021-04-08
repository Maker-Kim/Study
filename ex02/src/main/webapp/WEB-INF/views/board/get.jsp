<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>

<%@ include file="../includes/header.jsp"%>
<div class="row">
	<div class="col-lg-12">
		<h1 class="page-header">Board Read</h1>
	</div>
	<!-- /.col-lg-12 -->
</div>
<!-- /.row -->
<div class="row">
	<div class="col-lg-12">
		<div class="panel panel-default">
			<div class="panel-heading">Board Read</div>
			<!-- /.panel-heading -->
			<div class="panel-body">
			
				<div class="form-group">
					<label>BNO</label> <input class="form-control" name="title"
						readonly="readonly" value="<c:out value="${board.bno}"/>">
				</div>

				<div class="form-group">
					<label>Title</label> <input class="form-control" name="title"
						readonly="readonly" value="<c:out value="${board.title}"/>">
				</div>

				<div class="form-group">
					<label>Content</label>
					<textarea rows="5" cols="50" name="content" class="form-control"><c:out
							value="${board.content}" /></textarea>
				</div>

				<div class="form-group">
					<label>Writer</label> <input class="form-control" name="writer"
						value="<c:out value="${board.writer}"/>">
				</div>
				<button type="submit" class="btn btn-default"><a href='/board/list'>List</a></button>
				<button type="reset" class="btn btn-default"><a href='/board/modify?bno=<c:out value="${board.bno}"/>'>Modify</a></button>

			</div>
			<!-- /.panel-body -->
		</div>
		<!-- /.panel -->
	</div>
	<!-- /.col-lg-12 -->
</div>
<!-- /.row -->

<%@ include file="../includes/footer.jsp"%>