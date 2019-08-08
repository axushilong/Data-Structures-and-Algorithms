#ifndef DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLIST_HPP_
#define DATA_STRUCTURES_LINKLIST_DOUBLELINKLIST_DOUBLELINKLIST_HPP_

#include "doublelinklistnode.hpp"

template <typename T>
class DoubleLinkList
{
public:
    DoubleLinkList()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
    DoubleLinkList(const DoubleLinkList &obj) = delete;
    DoubleLinkList &operator=(const DoubleLinkList &obj) = delete;
    ~DoubleLinkList()
    {
        Destroy();
    }

public:
    /**
     * @function    创建双向链表。
     * @paras       none 。
     * @return      none .
     * @author      xuchanglong
     * @time        2019-08-08
     */
    void Create()
    {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    /**
     * @function    销毁双向链表。
     * @paras       none 。
     * @return      0   操作成功。
     *              -1  链表为空。
     * @author      xuchanglong
     * @time        2019-08-08
     */
    void Destroy()
    {

        DoubleLinkListNode *ptmp = nullptr;
        while (size_)
        {
            ptmp = head_;
            head_ = head_->prev;
            head_->next = nullptr;

            delete ptmp;
            ptmp = nullptr;
            size_--;
        }
    }

    /**
     * @function    向链表的头部插入新的数据。
     * @paras       pdata   待插入的数据。
     * @return      0   操作成功。
     *              -1  pdata == nullptr
     * @author      xuchanglong
     * @time        2019-08-08
     */
    int InsertHead(T *pdata)
    {
        if (pdata == nullptr)
        {
            return -1;
        }
        DoubleLinkListNode *pnode = new DoubleLinkListNode;
        memset(pnode, 0, sizeof(DoubleLinkListNode) * 1);

        pnode->data = pdata;
        pnode->prev = head_;
        head_->next = pnode;

        head_ = pnode;
        size_++;
        return 0;
    }

    /**
     * @function    删除链表尾部数据。
     * @paras       none 。
     * @return      0   操作成功。
     *              -1  链表为空。
     * @author      xuchanglong
     * @time        2019-08-08
     */
    int RemoveTail()
    {
        if (size_ == 0)
        {
            return -1;
        }
        DoubleLinkListNode *pnode = tail_;
        tail_ = tail_->next;
        tail_->prev = nullptr;

        delete pnode;
        pnode = nullptr;
        size_--;

        return 0;
    }

    /**
     * @function    删除链表中指定的节点。
     * @paras       pnode   待删除的节点。
     * @return      0   操作成功。
     *              -1  pnode == nullptr
     * @author      xuchanglong
     * @time        2019-08-08
     */
    int RemoveNode(DoubleLinkListNode<T> *pnode)
    {
        if (pnode == nullptr)
        {
            return -1;
        }

        if (pnode == head_)
        {
            head_ = head_->prev;
            head_->next = nullptr;

            delete pnode;
            pnode = nullptr;
        }
        else if (pnode == tail_)
        {
            tail_ = tail_->next;
            tail_->next = nullptr;

            delete pnode;
            pnode = nullptr;
        }
        else
        {
            pnode->prev->next = pnode->next;
            pnode->next->prev = pnode->prev;

            delete pnode;
            pnode = nullptr;
        }

        size_--;
        return 0;
    }

    /**
     * @function    搜索链表中指定数据的节点，并返回第一个。（从头部开始搜索）
     * @paras       data   待搜索的数据。
     * @return      非空    操作成功。
     *              空      未找到指定数据的节点。
     * @author      xuchanglong
     * @time        2019-08-08
     */
    DoubleLinkListNode<T> *SearchNode(const T &data)
    {
        DoubleLinkListNode *ptmp = head_;
        while (ptmp)
        {
            if (*(ptmp->data) == data)
            {
                return ptmp;
            }
            ptmp = ptmp->tail_;
        }
        return nullptr;
    }

    /**
     * @function    返回链表中节点数量。
     * @paras       none 。
     * @return      链表中的节点数量。
     * @author      xuchanglong
     * @time        2019-08-08
     */
    size_t Size()
    {
        return size_;
    }

private:
    /**
     * 指向头节点。
     */
    DoubleLinkListNode<T> *head_;

    /**
     * 指向尾节点。
     */
    DoubleLinkListNode<T> *tail_;

    /**
     * 链表中节点的数量。
     */
    size_t size_;
}

#endif