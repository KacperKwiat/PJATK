
<html>
<head>
    <title>Golden Horizon BAnk</title>
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
</head>
</html>
<a href="logout.php" style="position:absolute; top:0; right:0;width: 150px"><button style="width: 150px" >Log out</button></a>
<?php
session_start();
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessful connection");

if(isset($_POST['login'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $result=$db->query("select *from logins where login ='$login'");?>

    <?php
    if($result->rowCount()==0){
        $Nsql="INSERT INTO `logins` (`id`, `login`, `password`) VALUES (NULL, '$login', '$password')";
        $db->query($Nsql);
        $accNum=null;
        do{
            for($i=0;$i<26;$i++){
                $Num=rand(1,9);
                $accNum .=$Num;
            }
        }while($db->query("select * from account where number='$accNum' ")==0);


        $result=$db->query("select id from logins where login='$login'");
        $id=$result->fetch(PDO::FETCH_OBJ);
        $user=0;
        foreach ($id as $value){
            $user=$value;
        }
        $sql_2="INSERT INTO `account` (`id`, `number`, `money_amount`,`logins_fk` ) VALUES (NULL, '$accNum', 50, '$user')";
        $db->query($sql_2);

        echo "As thank you for creating account in our bank we give you 50PLN for your first transaction".'<br>'." Now try to log into your new account";

        header("refresh:5;url=LoginForm.php");


    }else{
        echo "Chosen login name is already taken";
    }
}else{
    echo "None data was recived";
}

?>