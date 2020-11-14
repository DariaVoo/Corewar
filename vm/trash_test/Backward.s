.name    "Back"
.comment "sebc"

	ld	%4, r3
	sti	r1, 1, %0
l1:	live	%-1
	ld	%:l1, r2
l3:	ldi	%:l2, r2, r4
	sti	r4, %:l2, r2
	add	r2, r3, r2
live:
	xor	r4, r4, r4
l2:
	add	r2, r3, r2
