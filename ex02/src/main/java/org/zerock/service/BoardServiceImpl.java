package org.zerock.service;

import java.util.List;

import org.springframework.stereotype.Service;
import org.zerock.domain.BoardVO;
import org.zerock.mapper.BoardMapper;

import lombok.RequiredArgsConstructor;
import lombok.ToString;
import lombok.extern.log4j.Log4j;

@Service
@Log4j
@RequiredArgsConstructor
@ToString
public class BoardServiceImpl implements BoardService{

	private final BoardMapper mapper;
	
	@Override
	public Long register(BoardVO board) {
		
		mapper.insertSelectKey(board);
		
		return board.getBno();
		
	}
	
	@Override
	public BoardVO get(Long bno) {
		
		return mapper.read(bno);
	}

	@Override
	public int modify(BoardVO board) {
		
		return mapper.update(board);
	}

	@Override
	public int remove(Long bno) {
		
		return mapper.delete(bno);
	}

	@Override
	public List<BoardVO> getList() {
		
		return mapper.getList();
	}
	
}
