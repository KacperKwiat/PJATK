<?php
$cookie_name = "vote";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Bank Survey</title>
</head>
<body>

<?php
if(!isset($_COOKIE[$cookie_name])) {
    ?>
    <h1>Client Satisfaction Survey</h1>
    <form action="temp.php" method="post">
        <p>Write down your email address:</p>
        <input type="email" placeholder="Enter your email">
        
        <p>Your opinion write down here</p>
        <input type="textarea" placeholder="Write your opionion here">
        
        <input type="submit" name="submit" value="Submit">
    </form>
<?php
} else {
    echo "Cookie " . $cookie_name . " is set!";
    echo "You have already shared your opinion ";
}
?>

</body>
</html>
