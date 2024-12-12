use societe;

create trigger tfo1 on users for insert
as
begin
print 'bien ajoutee users';
end
insert into users values (1,'salwa',15,'salwa22@g.com'),
                         (2,'hakia',20,'haki22@g.com'),
						 (3,'hicha',15,'hicha122@g.com')
select * from users