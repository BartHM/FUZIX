
	.export __stbyte3

	.setcpu 8080
	.code
__stbyte3:
	mov a,l
	lxi h,3

	mov m,a
	mov l,a
	ret