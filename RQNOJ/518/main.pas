program p518;
var s1,s2,want:string;
	will:array ['A'..'Z'] of char;
	done:array['A'..'Z'] of boolean;
	c:char;
	i:integer;
	found:array['A'..'Z'] of char;
begin
	readln(s1);
	readln(s2);
	readln(want);
	if (length(s1)<26) then begin
		writeln('Failed');
		halt;
	end;
	for i:=1 to length(s1) do
		begin
			if ((found[s2[i]]<>chr(0))and(found[s2[i]]<>s1[i]))then begin
				writeln('Failed');
				halt;
			end;
			if (not done[s1[i]]) then
			begin
				done[s1[i]]:=true;
				will[s1[i]]:=s2[i];
				found[s2[i]]:=s1[i];
			end
			else
				begin
					if (will[s1[i]]<>s2[i]) then
						begin
							writeln('Failed');
							halt;
						end;
				end;
		end;
	for c:='A' to 'Z' do
		if (not done[c]) then
			begin
				writeln('Failed');
				halt;
			end;
	for i:=1 to length(want) do
		begin
			write(will[want[i]]);
		end;
	writeln();
end.
