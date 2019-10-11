$(function(){
    var $orders = $('#orders');
    var $name = $('#name');
    var $age = $('#age');

    $.ajax({
        type: 'GET',
        url:'data.json',
        success: function(data){
            $.each(data, function(index,info){
                $orders.append('<li> name ' +info.name + ' age ' + info.age + '</li>')
            })
        },
        error: function(){
            alert('error loading orders');
        }
        
    });

    $('#add-data').on('click', function(){
        var info = {
            name: $name.val(),
            age: $age.val()
        };
        $.ajax({
            type:'POST',
            url:'data.json',
            data: info,
            success: function(newData){
                    $orders.append('<li> name ' +newData.name + ' age ' + newData.age + '</li>');
            }
        });


    });
});