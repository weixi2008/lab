import numpy as np
from random import shuffle

# 在计算损失的同时，也计算了梯度。使用了分析梯度法，而非数值梯度法。
def svm_loss_naive(W, X, y, reg):
  """
  Structured SVM loss function, naive implementation (with loops).

  Inputs have dimension D, there are C classes, and we operate on minibatches
  of N examples.

  Inputs:
  - W: A numpy array of shape (D, C) containing weights.
  - X: A numpy array of shape (N, D) containing a minibatch of data.
  - y: A numpy array of shape (N,) containing training labels; y[i] = c means
    that X[i] has label c, where 0 <= c < C.
  - reg: (float) regularization strength

  Returns a tuple of:
  - loss as single float
  - gradient with respect to weights W; an array of same shape as W
  """
  dW = np.zeros(W.shape) # initialize the gradient as zero

  # compute the loss and the gradient
  num_classes = W.shape[1]
  num_train = X.shape[0]
  loss = 0.0
  for i in range(num_train):
    scores = X[i].dot(W) # 一个图像的所有分类的得分 1 * C
    correct_class_score = scores[y[i]] # 此图像正确分类的得分
    # 利用Multiclass SVM loss的公式：loss = sum(max(0, sj - syj + delta)) + 0.5 * reg * L2(W) 其中ｊ不等于yj。也就是正确分类的损失不计算在内。
    for j in range(num_classes):
      if j == y[i]:
        continue
      margin = scores[j] - correct_class_score + 1 # note delta = 1
      if margin > 0:
        loss += margin
        # 此处使用微分分析法，计算梯度。
        # 根据讲义，只需要计算没有满足边界值的分类的数量（因此对损失函数产生了贡献），然后乘以x_i就是梯度了。
        dW[:, j] += X[i].T
        dW[:, y[i]] += -X[i].T

  # Right now the loss is a sum over all training examples, but we want it
  # to be an average instead so we divide by num_train.
  loss /= num_train
  dW /= num_train

  # Add regularization to the loss.
  loss += 0.5 * reg * np.sum(W * W)
  # 【问题】梯度的计算，也需要正则化吗？
  dW += reg * W

  #############################################################################
  # TODO:                                                                     #
  # Compute the gradient of the loss function and store it dW.                #
  # Rather that first computing the loss and then computing the derivative,   #
  # it may be simpler to compute the derivative at the same time that the     #
  # loss is being computed. As a result you may need to modify some of the    #
  # code above to compute the gradient.                                       #
  #############################################################################

  return loss, dW


def svm_loss_vectorized(W, X, y, reg):
  """
  Structured SVM loss function, vectorized implementation.

  Inputs and outputs are the same as svm_loss_naive.
  """
  loss = 0.0
  dW = np.zeros(W.shape) # initialize the gradient as zero

  #############################################################################
  # TODO:                                                                     #
  # Implement a vectorized version of the structured SVM loss, storing the    #
  # result in loss.                                                           #
  #############################################################################
  num_classes = W.shape[1]
  num_train = X.shape[0]
  scores = X.dot(W) # N * C
  correct_class_scores = scores[range(num_train), y].reshape(num_train, 1) # N * 1
  margins = np.maximum(0, scores - correct_class_scores + 1.0) # delta = 1.0
  margins[range(num_train), y] = 0
  loss = np.sum(margins) / num_train + reg * np.sum(W * W) / 2.0
  #############################################################################
  #                             END OF YOUR CODE                              #
  #############################################################################


  #############################################################################
  # TODO:                                                                     #
  # Implement a vectorized version of the gradient for the structured SVM     #
  # loss, storing the result in dW.                                           #
  #                                                                           #
  # Hint: Instead of computing the gradient from scratch, it may be easier    #
  # to reuse some of the intermediate values that you used to compute the     #
  # loss.                                                                     #
  #############################################################################
  counts = (margins > 0).astype(int)
  counts[range(num_train), y] = - np.sum(counts, axis = 1)
  dW += np.dot(X.T, counts) / num_train + reg * W

  # 其他代码
  # coeff_mat = np.zeros((num_train, num_classes))
  # coeff_mat[margins > 0] = 1
  # coeff_mat[range(num_train), list(y)] = 0
  # coeff_mat[range(num_train), list(y)] = -np.sum(coeff_mat, axis=1)
  #
  # dW = (X.T).dot(coeff_mat)
  # dW = dW/num_train + reg*W
  #############################################################################
  #                             END OF YOUR CODE                              #
  #############################################################################

  return loss, dW
