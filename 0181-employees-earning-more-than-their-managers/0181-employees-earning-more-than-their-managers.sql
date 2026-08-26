# Write your MySQL query statement below
select e.name as employee from employee as e
join employee as m on e.managerId = m.Id where e.salary>m.salary