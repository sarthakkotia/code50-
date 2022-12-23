-- select movies released in 2004
-- their id
-- find person_id from movies.id
--show people from person_id
--list their names
--order by

SELECT name FROM people WHERE id in (SELECT person_id FROM stars WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004)) ORDER BY birth;