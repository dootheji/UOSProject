//�ϴ� ��ũ���� �׸��� �׸���	
//16384~16415�� �� ��
//���� �������� �� ���� ������ �������� ����

///////////////////////////���� �� �ߴ� ��
(DRAW)
	@SCREEN
	M=1
	D=A+1
	@24576
	M=D
	
	(VIR)
	@24576
	D=M
	A=D
	M=1
	D=A+1
		

	@24576
	M=A-D
	D=M
	M=A-D

	@VIR	//LOOP
	D;JNE
	@VIRTURE
	D;JLE


	///������ �߱� �����ϴ� ����Ʈ ����
(VIRTURE)
	@15904
	D=A
	@480
	M=D+A

	//�� �߱� ������ ����Ʈ ����
	@15935
	D=A
	@481
	D=D-1
	M=D+A

	//�ٱ߱� ����
	(ROWSTART)
	@480
	A=M
	M=-1
	D=A+1
	A=D
	M=-1
	@482
	M=D

	(ROW)
	@482
	D=M+1
	A=D
	M=-1
	
	// �����ΰ��� ���̸� �����ؾ���
	@482
	M=D
	@481
	D=M-D
	
	//16864�� ���� ���� ����
	
	@ROW
	D;JGT
	@NEXTROW
	D;JEQ
	
	(NEXTROW)
	@480
	D=M
	D=D+A
	M=D
	@481
	D=M-1
	D=D+A
	M=D
	@24576
	D=A-D
	@ROWSTART
	D;JGT
	@24576
	D=M
	@POINT
	D;JEQ


//�簢�� ���� ���� ���������
//20240�ε� �ű⿡�� ���������ϰ�

///////////////////////////////////////////////////////////////
//MAKE STARTING POINT (16,8)
(POINT)
	@20240
	D=A
	@777
	M=D

///////////////////////////////////////////////////////////////////

/////////////////////////
///MAKE RECTANGLE 
(MAKERECTANGLE)
	@480
	M=A
	@16
	M=A


	@777
	A=M
	M=-1
	D=A
	
	@32
	M=D

	(LOOPFORREC)
	@32
	D=M
	D=A+D
	M=D
	A=D
	M=-1
	
	///RAM16���� �����ϱ�
	@16
	M=M-1
	D=M
	@LOOPFORREC
	D;JGT
	@KEYBOARD
	D;JLE



//////////////////////////////////////////////////////////////////

(DELETERECTANGLE)
	@480
	M=A
	@16
	M=A


	@777
	A=M
	M=1
	D=A
	
	@32
	M=D

	(LOOPFORDELETE)
	@32
	D=M
	D=A+D
	M=D
	A=D
	M=1
	
	///RAM16���� �����ϱ�


	@16
	M=M-1
	D=M
	@LOOPFORDELETE
	D;JGT

//������ �ٽ� �׸���
	@777
	A=M
	M=-1
	D=A
	@480
	D=A+D
	A=D
	M=-1

	@16
	D=M
	@WAITLINE
	D;JLE



////////////////////////////////////////////////////////
//////////Ű���� �Է¹ޱ�


(KEYBOARD)
	//Ű���� ��ư ���� #111�� �����صд�
	(START)
	@KBD
	D=M
	@111
	M=D
	@START
	D;JEQ
	//��ư�� ������ ���ڸ� �����
	(CHECK)
	@DELETERECTANGLE
	D;JNE
	
	//�ΰ����� ���� WAITLINE
	(WAITLINE)
	@KBD
	D=M
	@WAITLINE
	D;JNE



	//�����ϱ�?
	@130
	D=A
	@111
	D=M-D
	@GOTOLEFT
	D;JEQ

	//�����ϱ�?
	@131
	D=A
	@111
	D=M-D
	@GOUP
	D;JEQ

	//�������ϱ�?
	@132
	D=A
	@111
	D=M-D
	@GOTORIGHT
	D;JEQ

	//�Ʒ����ϱ�?
	@133
	D=A
	@111
	D=M-D
	@GODOWN
	D;JEQ



///////////////////////////////////////////////////////////////////
//GO TO LEFT

(GOTORIGHT)	
	@777
	M=M+1
	@MAKERECTANGLE
	D;JMP


(GOTOLEFT)	
	@777
	M=M-1
	@MAKERECTANGLE
	D;JMP
	

(GOUP)
	@480
	D=A
	@777
	M=M-D
	@MAKERECTANGLE
	D;JMP


	
(GODOWN)
	@480
	D=A
	@777
	M=M+D
	@MAKERECTANGLE
	D;JMP
	