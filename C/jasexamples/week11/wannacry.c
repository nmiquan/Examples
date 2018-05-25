
unsigned int __fastcall SrvOs2FeaToNt(int a1, int a2) {
  int v4; // edi@1
  _BYTE *v5; // edi@1
  unsigned int result; // eax@1
  _BYTE *source, *dest;  int nbytes;

  v4 = a1 + 8;
  *(_BYTE *)(a1 + 4) = *(_BYTE *)a2;
  *(_BYTE *)(a1 + 5) = *(_BYTE *)(a2 + 1);
  *(_WORD *)(a1 + 6) = *(_WORD *)(a2 + 2);
  
  dest = (a1 + 8);
  source = (a2 + 4);
  nbytes = *(_BYTE *)(a2 + 1);
  _memmove((void *)dest, (void *)source, nbytes);
  
  v5 = (_BYTE *)(*(_BYTE *)(a1 + 5) + v4);
  *v5++ = 0;
  dest = v5;
  source = a2 + 5 + *(_BYTE *)(a1 + 5);
  nbytes = *(_WORD(a1 + 6);
  _memmove(dest, (void *)source, nbytes); // BUG!
  
  result = (unsigned int)&v5[*(_WORD *)(a1 + 6) + 3];
  result = result & 0xFFFFFFFC;
  *(_DWORD *)a1 = result - a1;
  return result;
}
