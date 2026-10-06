# Write your MySQL query statement below
with temp as(
    select managerId from Employee group by managerId having count(*) >= 5
),
temp2 as (
    select id, name from Employee
)
select t2.name from temp2 t2 inner join temp t1 on t1.managerId = t2.id; 