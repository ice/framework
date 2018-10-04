<?php

namespace Tests\App\Models;

use Ice\Mvc\Model;

class Comments extends Model
{
    protected $fields = [
        'id',
        'user_id',
        'post_id',
        'content',
        'status',
        'created'
    ];

    public function initialize()
    {
        $this
            ->belongsTo('user_id', __NAMESPACE__ . '\Users', $this->getIdKey(), ['alias' => 'User'])
            ->belongsTo('post_id', __NAMESPACE__ . '\Posts', $this->getIdKey(), ['alias' => 'Post']);
    }
}
