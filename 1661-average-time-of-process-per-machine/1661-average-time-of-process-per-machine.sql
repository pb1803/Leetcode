# Write your MySQL query statement below
select a.machine_id,round(avg(e.timestamp-a.timestamp),3) as processing_time
from activity as a join activity as e 
on (a.machine_id=e.machine_id and a.process_id=e.process_id) where 
a.activity_type = 'start' and e.activity_type = 'end' group by machine_id