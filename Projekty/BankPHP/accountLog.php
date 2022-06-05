<?php
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessfulconnection");

if(isset($_POST['submit'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $sql="select *from logins where login ='$login' AND password ='$password'";
    $result=$db->query($sql);
    if($result->rowCount()==1){
        $result=$db->query("select id from logins where login='$login'");
        $id=$result->fetch(PDO::FETCH_OBJ);
        $user=0;
        foreach ($id as $value){
            $user=$value;
        }
        $sql_3="Select number from account where logins_fk='$user'";
        $num=$db->query($sql_3);
        $number=$num->fetch(PDO::FETCH_OBJ);

        $accountNumber=0;
        foreach ($number as $acc){
            $accountNumber= $acc;

        }

        echo "Your bank account number is ".$accountNumber.'<br>';
        $sql_4="Select money_amount from account where logins_fk='$user'";
        $m=$db->query($sql_4);
        $amount=$m->fetch(PDO::FETCH_OBJ);
        $money=0;
        foreach ($amount as $mon){
            $money= $mon;

        }
        echo "Your bank balance is ".$money.' PLN'.'<br>';

    }else{
        echo "You have entered wrong password or login";
    }
}else{
    echo "None data was recived";
}

?>