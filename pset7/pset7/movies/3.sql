--write a SQL query to list the titles of all movies with a release date
--on or after 2018, in alphabetical order.

SELECT title
FROM movies
WHERE year >= 2018
--ORDER BY title ASC ;
ORDER BY
   CASE WHEN title LIKE '%[^a-zA-Z0-9]%' THEN 1
   ELSE 2 END, title;