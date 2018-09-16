<?php

namespace Tests\App\Models;

use Ice\Mvc\Model;

class Posts extends Model
{
    protected $fields = [
        'id',
        'user_id',
        'title',
        'content',
        'status',
        'created'
    ];

    public function initialize()
    {
        $this
            ->belongsTo('user_id', __NAMESPACE__ . '\Users', $this->getIdKey(), ['alias' => 'User'])
            ->hasMany($this->getIdKey(), __NAMESPACE__ . '\Comments', 'post_id', ['alias' => 'Comments']);
    }
}
