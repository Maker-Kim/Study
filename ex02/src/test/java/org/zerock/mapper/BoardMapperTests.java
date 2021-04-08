package org.zerock.mapper;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.zerock.domain.BoardVO;

import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class BoardMapperTests {
	
	@Autowired
	private BoardMapper boardMapper;
	
	@Test
	public void testGetList() {
		
		log.info("-------------------------");
		boardMapper.getList();
		
	}
	
	@Test
	public void testInsert() {
		
		
		BoardVO vo = new BoardVO();
		vo.setTitle("Test 테스트");
		vo.setContent("Content 테스트");
		vo.setWriter("Tester");
		
		boardMapper.insert(vo);
		
		log.info("-------------------------");
		log.info("after insert" + vo.getBno());
	}
	
	//위의 Insert랑 다른점은 여기는 몇번에 들어가는지 확인 가능
	@Test
	public void testInsertSelectkey() {
		
		BoardVO vo = new BoardVO();
		vo.setTitle("AAATest 테스트");
		vo.setContent("AAAContent 테스트");
		vo.setWriter("TesterA");
		
		boardMapper.insertSelectKey(vo);
		
		log.info("-------------------------");
		log.info("after insert selectkey" + vo.getBno());
	}
	
	@Test
	public void testRead() {
		
		BoardVO vo = boardMapper.read(8L);
		log.info(vo);
		
	}
	
	@Test
	public void testDelete() {
		int count = boardMapper.delete(1L);
		log.info("갯수: " + count);
	}
	
	@Test
	public void testUpdate() {
		
		BoardVO vo = new BoardVO();
		vo.setBno(8L);
		vo.setTitle("Update Title");
		vo.setContent("Updated content");
		vo.setWriter("user00");
		
		log.info("갯수: " + boardMapper.update(vo));
	}
	

}
