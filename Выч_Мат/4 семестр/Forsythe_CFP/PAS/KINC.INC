{$IFOPT N+}
type
  Float = double; { 8 byte real, requires 8087 math chip }
{$ELSE}
type
  Float = real;   { 6 byte real, no math chip required }
{$ENDIF}
{$V-}
