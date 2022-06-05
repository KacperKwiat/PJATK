<?php
$dbuser = 'root';
$dbpass = '';
$db = new PDO("mysql:host=localhost;dbname=projekt", $dbuser,$dbpass) or die ("Unsuccessful connection");

if(isset($_POST['login'])){
    $login=$_POST['login'];
    $password=$_POST['password'];
    $result=$db->query("select *from logins where login ='$login'");

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

        echo "As thank you for creating account in our bank we give you 50PLN for your first transaction".'<br>';
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
        echo "Chosen login name is already taken";
    }
}else{
    echo "None data was recived";
}

?>